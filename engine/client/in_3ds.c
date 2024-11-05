//Generic input code.
//mostly mouse support, but can also handle a few keyboard events.

//Issues:

//VirtualBox mouse integration is bugged. X11 code can handle tablets, but VirtualBox sends mouse clicks on the ps/2 device instead.
//  you should be able to fix this with 'in_deviceids * 0 *', remapping both tablet+ps/2 to the same device id. 

//Android touchscreen inputs suck. should have some onscreen buttons, but they're still a bit poo or something. blame mods for not using csqc to do things themselves.

#include "quakedef.h"

#include <3ds.h>

#include "keyboardOverlay_bin.h"
#include "touchOverlay_bin.h"

#ifndef K_AUX17
#define K_AUX17		223
#endif

#define JOY_LT_THRESHOLD -16384
#define JOY_RT_THRESHOLD -16384
#define JOY_SIDE_DEADZONE 0
#define JOY_FORWARD_DEADZONE 0
#define JOY_PITCH_DEADZONE 0
#define JOY_YAW_DEADZONE 0

static uint16_t *framebuffer;

static bool text_input = false;
static bool keyboard_enabled = false;
static bool shift_pressed = false;
static int button_pressed = 0;

static circlePosition cstick;
static circlePosition circlepad;
static touchPosition  touch, old_touch;

typedef struct buttonmapping_s{
	uint32_t btn;
	int key;
} buttonmapping_t;

static char keymap[2][14 * 6] = 
{
	{
		K_ESCAPE , K_F1, K_F2, K_F3, K_F4, K_F5, K_F6, K_F7, K_F8, K_F9, K_F10, K_F11, K_F12, 0,
		'`' , '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', K_BACKSPACE,
		K_TAB, 'q' , 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '|',
		0, 'a' , 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', K_ENTER, K_ENTER,
		K_SHIFT, 'z' , 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, K_UPARROW, 0,
		0, 0 , 0, 0, K_SPACE, K_SPACE, K_SPACE, K_SPACE, K_SPACE, K_SPACE, 0, K_LEFTARROW, 	K_DOWNARROW, K_RIGHTARROW
	},
	{
		K_ESCAPE , K_F1, K_F2, K_F3, K_F4, K_F5, K_F6, K_F7, K_F8, K_F9, K_F10, K_F11, K_F12, 0,
		'~' , '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', K_BACKSPACE,
		K_TAB, 'Q' , 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '|',
		0, 'A' , 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"', K_ENTER, K_ENTER,
		K_SHIFT, 'Z' , 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?', 0, K_UPARROW, 0,
		0, 0 , 0, 0, K_SPACE, K_SPACE, K_SPACE, K_SPACE, K_SPACE, K_SPACE, 0, K_LEFTARROW, 	K_DOWNARROW, K_RIGHTARROW
	}
};

static buttonmapping_t btnmap[14] =
{
	{ KEY_SELECT, (int)'~' },
	{ KEY_START, K_ESCAPE },
	{ KEY_DUP, K_UPARROW },
	{ KEY_DRIGHT, K_MWHEELUP },
	{ KEY_DDOWN, K_DOWNARROW },
	{ KEY_DLEFT, K_MWHEELDOWN },
	{ KEY_L, K_MOUSE2 },
	{ KEY_R, K_MOUSE1 },
	{ KEY_ZL, K_CTRL },
	{ KEY_ZR, 'r' },
	{ KEY_A, K_ENTER },
	{ KEY_B, K_SPACE },
	{ KEY_X, 'f' },
	{ KEY_Y, 'e' },
};

typedef enum engineAxis_e
{
	JOY_AXIS_SIDE = 0,
	JOY_AXIS_FWD,
	JOY_AXIS_PITCH,
	JOY_AXIS_YAW,
	JOY_AXIS_RT,
	JOY_AXIS_LT,
	JOY_AXIS_NULL
} engineAxis_t;

#define MAX_AXES JOY_AXIS_NULL

static engineAxis_t joyaxesmap[MAX_AXES] =
{
	JOY_AXIS_SIDE,  // left stick, x
	JOY_AXIS_FWD,   // left stick, y
	JOY_AXIS_PITCH, // right stick, y
	JOY_AXIS_YAW,   // right stick, x
	JOY_AXIS_RT,    // right trigger
	JOY_AXIS_LT     // left trigger
};

static struct joy_axis_s
{
	short val;
	short prevval;
} joyaxis[MAX_AXES] = { 0 };

static void DrawSubscreen()
{
	int x, y;
	uint16_t* overlay;

	if(keyboard_enabled)
		overlay = keyboardOverlay_bin;
	else
		overlay = touchOverlay_bin;

	memcpy(framebuffer, overlay, 240*320*2);

	if(keyboard_enabled && shift_pressed)
	{
		for(x = 20; x < 23; x++)
      		for(y = 152; y < 155; y++)
				framebuffer[(x*240 + (239 - y))] = RGB8_to_565(39, 174, 96);
	}

}

static void RescaleAnalog( int *x, int *y, float deadZone )
{
	float analogX = (float)*x;
	float analogY = (float)*y;
	float maximum = 180.0f;
	float magnitude = sqrtf( analogX * analogX + analogY * analogY );

	if( magnitude >= deadZone )
	{
		float scalingFactor = maximum / magnitude * ( magnitude - deadZone ) / ( maximum - deadZone );
		*x = (int)( analogX * scalingFactor );
		*y = (int)( analogY * scalingFactor );
	}
	else
	{
		*x = 0;
		*y = 0;
	}
}

static inline void UpdateAxes( void )
{
	hidCircleRead(&circlepad);
	hidCstickRead(&cstick);

	int left_x = circlepad.dx;
	int left_y = circlepad.dy;
	int right_x = cstick.dx;
	int right_y = cstick.dy;

	if( abs( left_x ) < 15.0f ) left_x = 0;
	if( abs( left_y ) < 15.0f ) left_y = 0;

	RescaleAnalog( &right_x, &right_y, 25.0f );

	Joy_AxisMotionEvent( 0, 0, left_x * 180 );
	Joy_AxisMotionEvent( 0, 1, left_y * -180 );

	Joy_AxisMotionEvent( 0, 2, right_x * -180 );
	Joy_AxisMotionEvent( 0, 3, right_y *  180 );
}

void Joy_AxisMotionEvent( int id, qbyte axis, short value )
{
	qbyte engineAxis;

	if( axis >= MAX_AXES )
	{
		return;
	}

	engineAxis = joyaxesmap[axis]; // convert to engine inner axis control

	if( engineAxis == JOY_AXIS_NULL )
		return;

	if( value == joyaxis[engineAxis].val )
		return; // it is not an update

	if( engineAxis >= JOY_AXIS_RT )
		Joy_ProcessTrigger( engineAxis, value );
	else
		Joy_ProcessStick( engineAxis, value );
}

void Joy_ProcessTrigger( const engineAxis_t engineAxis, short value )
{
	int trigButton = 0, trigThreshold = 0;

	switch( engineAxis )
	{
	case JOY_AXIS_RT:
		trigButton = K_JOY2;
		trigThreshold = JOY_RT_THRESHOLD;
		break;
	case JOY_AXIS_LT:
		trigButton = K_JOY1;
		trigThreshold = JOY_LT_THRESHOLD;
		break;
	default:
		break;
	}

	// update axis values
	joyaxis[engineAxis].prevval = joyaxis[engineAxis].val;
	joyaxis[engineAxis].val = value;

	if( joyaxis[engineAxis].val > trigThreshold &&
		joyaxis[engineAxis].prevval <= trigThreshold ) // ignore random press
	{
		Key_Event( 0, trigButton, 0, true );
	}
	else if( joyaxis[engineAxis].val < trigThreshold &&
			 joyaxis[engineAxis].prevval >= trigThreshold ) // we're unpressing (inverted)
	{
		Key_Event( 0, trigButton, 0, false );
	}
}

void Joy_ProcessStick( const engineAxis_t engineAxis, short value )
{
	int deadzone = 0;

	switch( engineAxis )
	{
	case JOY_AXIS_FWD:   deadzone = JOY_FORWARD_DEADZONE; break;
	case JOY_AXIS_SIDE:  deadzone = JOY_SIDE_DEADZONE; break;
	case JOY_AXIS_PITCH: deadzone = JOY_PITCH_DEADZONE; break;
	case JOY_AXIS_YAW:   deadzone = JOY_YAW_DEADZONE; break;
	default:
		break;
	}

	if( value < deadzone && value > -deadzone )
		value = 0; // caught new event in deadzone, fill it with zero(no motion)

	// update axis values
	joyaxis[engineAxis].prevval = joyaxis[engineAxis].val;
	joyaxis[engineAxis].val = value;

    // ??
	// fwd/side axis simulate hat movement
	/*if( ( engineAxis == JOY_AXIS_SIDE || engineAxis == JOY_AXIS_FWD ) &&
		( CL_IsInMenu() || CL_IsInConsole() ) )
	{
		int val = 0;

		val |= Joy_GetHatValueForAxis( JOY_AXIS_SIDE );
		val |= Joy_GetHatValueForAxis( JOY_AXIS_FWD );

		Joy_HatMotionEvent( JOY_SIMULATED_HAT_ID, 0, val );
	}*/
}

static inline void UpdateButtons( void )
{
	for(int i = 0; i < 14; i++)
	{
		if( ( hidKeysDown() & btnmap[i].btn ) )
				Key_Event( 0, btnmap[i].key, 0, true );
		else if( ( hidKeysUp() & btnmap[i].btn ) )
				Key_Event( 0, btnmap[i].key, 0, false );
	}
}

static inline void UpdateTouch( void )
{
	if(hidKeysDown() & KEY_TOUCH)
	{
		if(touch.py < 42 && touch.py > 1)
		{
			button_pressed = K_AUX17 + (touch.px / 80);
		}

		if(keyboard_enabled && touch.py > 59 && touch.py < 193 && touch.px > 6 && touch.px < 314)
		{
			int key_num = ((touch.py - 59) / 22) * 14 + (touch.px - 6) / 22;

			if(text_input)
			{
				char character = keymap[shift_pressed][key_num];

				if(character == K_SHIFT)
				{
					shift_pressed = !shift_pressed;
					DrawSubscreen();
				}
				if(character < 32 || character > 126)
				{
					button_pressed = character;
				}
				else
				{
                    // todo text input events
					// CL_CharEvent( character );
				}
			}
			else
			{
				button_pressed = keymap[0][key_num];
			}
		}

		if(touch.py > 213 && touch.px > 135 && touch.px < 185)
		{
			keyboard_enabled = !keyboard_enabled;
			DrawSubscreen();
		}

		if(button_pressed)
		{
			Key_Event( 0, button_pressed, 0, true );
		}
	}
	else if(hidKeysHeld() & KEY_TOUCH)
	{
		if(!button_pressed)
		{
            // todo touch events
			// IN_TouchEvent( event_motion, 0, touch.px / 400.0f, touch.py / 300.0f, (touch.px - old_touch.px) / 400.0f, (touch.py - old_touch.py) / 300.0f );
		}
	}
	else if(hidKeysUp() & KEY_TOUCH)
	{
		if(button_pressed)
		{
			Key_Event( 0, button_pressed, 0, false );
		}

		button_pressed = 0;
	}

	old_touch = touch;
}

void ctr_EnableTextInput( int enable, qboolean force )
{
	text_input = enable;
}

void INS_Init (void)
{
    framebuffer = (uint16_t*)gfxGetFramebuffer(GFX_BOTTOM, GFX_LEFT, NULL, NULL);
	DrawSubscreen();
}

void INS_Commands (void)
{
    hidScanInput();
	hidTouchRead(&touch);
	UpdateAxes();
	UpdateButtons();
	UpdateTouch();
}

enum controllertype_e INS_GetControllerType(int id)
{
    return CONTROLLER_NINTENDO;
}

void INS_Rumble(int id, quint16_t amp_low, quint16_t amp_high, quint32_t duration)
{
}

void INS_RumbleTriggers(int id, quint16_t left, quint16_t right, quint32_t duration)
{
}

void INS_SetLEDColor(int id, vec3_t color)
{
    // todo(?)
}

void INS_SetTriggerFX(int id, const void *data, size_t size)
{
}

void INS_Shutdown (void)
{
}

void INS_ReInit (void)
{
}

void INS_EnumerateDevices(void *ctx, void(*callback)(void *ctx, const char *type, const char *devicename, unsigned int *qdevid))
{
}

void INS_Move(void)
{
}
