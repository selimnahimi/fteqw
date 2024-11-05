PREFIX    = $(DEVKITARM)/bin/arm-none-eabi
CC        = $(PREFIX)-gcc
CXX       = $(PREFIX)-g++
AR        = $(PREFIX)-ar

INCLUDES = -I. -I./models -I./quake3 -I./quake3/botlib -I../engine/client -I../engine/common -I../engine/qclib -I../engine/gl
DEFINES = -D__3DS__ -DFTEPLUGIN
CFLAGS =  -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -O2 -Wl,-q -Wfatal-errors -Wno-write-strings -fsigned-char -fno-short-enums -ffunction-sections -fdata-sections $(DEFINES) $(INCLUDES)
CXXFLAGS = $(CFLAGS) -fno-exceptions -std=gnu++11 -fno-threadsafe-statics -fpermissive -static-libstdc++ -static-libgcc -Wno-invalid-offsetof
ASFLAGS = $(CFLAGS)

GLTF_OBJS = models/draco.o models/exportiqm.o models/gltf.o models/models.o
QUAKE3_OBJS = quake3/clq3_cg.o quake3/clq3_parse.o quake3/q3common.o quake3/svq3_game.o

libgltf.a: $(GLTF_OBJS)
	$(AR) rcs $@ $^

libquake3.a: $(QUAKE3_OBJS)
	$(AR) rcs $@ $^

all: libgltf.a libquake3.a

clean:
	rm -f $(GLTF_OBJS) libgltf.a
	rm -f $(QUAKE3_OBJS) libquake3.a