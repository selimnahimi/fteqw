COMMON_OBJS = \
	gl_alias.o		\
	gl_hlmdl.o	\
	gl_heightmap.o		\
	gl_model.o	\
	com_bih.o	\
	com_mesh.o	\
	common.o 		\
	json.o		\
	cvar.o 		\
	cmd.o 		\
	crc.o 		\
	net_ssl_gnutls.o \
	net_master.o	\
	fs.o			\
	fs_stdio.o		\
	fs_pak.o		\
	fs_zip.o		\
	fs_dzip.o		\
	fs_xz.o		\
	m_download.o	\
	mathlib.o 		\
	huff.o		\
	md4.o 		\
	md5.o 		\
	sha1.o		\
	sha2.o		\
	log.o 		\
	net_chan.o 		\
	net_wins.o 		\
	net_ice.o 		\
	httpclient.o 	\
	zone.o 		\
	qvm.o	\
	r_d3.o	\
	gl_q2bsp.o		\
	glmod_doom.o 	\
	world.o 		\
	sv_phys.o 		\
	sv_move.o 		\
	pmove.o		\
	pmovetst.o		\
	iwebiface.o		\
	translate.o		\
	plugin.o		\
	q1bsp.o		\
	q2pmove.o

CLIENT_OBJS = \
	textedit.o	\
	fragstats.o	\
	zqtp.o	\
	cl_demo.o	\
	cl_ents.o	\
	clq2_ents.o	\
	cl_input.o	\
	in_generic.o	\
	cl_main.o	\
	cl_parse.o	\
	cl_pred.o	\
	cl_tent.o	\
	cl_cam.o	\
	cl_screen.o	\
	pr_clcmd.o	\
	cl_ignore.o \
	pr_csqc.o	\
	console.o	\
	image.o	\
	keys.o	\
	menu.o	\
	m_master.o	\
	m_multi.o	\
	m_items.o	\
	m_options.o	\
	m_single.o	\
	m_script.o	\
	m_native.o	\
	m_mp3.o	\
	roq_read.o	\
	clq2_cin.o	\
	r_part.o	\
	p_script.o	\
	p_null.o	\
	p_classic.o	\
	r_partset.o	\
	renderer.o	\
	renderque.o	\
	sbar.o	\
	skin.o	\
	snd_al.o	\
	snd_dma.o	\
	snd_mem.o	\
	snd_mix.o	\
	snd_mp3.o	\
	snd_ov.o	\
	valid.o	\
	vid_headless.o	\
	view.o	\
	wad.o			\
				\
	ftpclient.o		\
				\
				\
	pr_menu.o

GLQUAKE_OBJS =		\
	gl_draw.o		\
	gl_backend.o		\
	gl_rmain.o		\
	gl_rmisc.o		\
	gl_rsurf.o		\
	gl_screen.o		\
	gl_bloom.o		\
	gl_vidcommon.o		\
	$(VKQUAKE_OBJS)

VKQUAKE_OBJS =		\
	vk_init.o	\
	vk_backend.o

QCC_OBJS=	\
	comprout.o		\
	hash.o		\
	qcc_cmdlib.o	\
	qccmain.o		\
	qcc_pr_comp.o	\
	qcc_pr_lex.o	\
	qcd_main.o
PROGS_OBJS =		\
	$(QCC_OBJS)	\
	initlib.o		\
	pr_bgcmd.o		\
	pr_skelobj.o		\
	pr_edict.o		\
	pr_exec.o		\
	pr_multi.o		\
	pr_x86.o		\
	qcdecomp.o

D3DGL_OBJS =		\
	gl_font.o \
	gl_ngraph.o		\
	gl_shader.o	\
	gl_shadow.o	\
	gl_rlight.o	\
	gl_warp.o	\
	ltface.o	\
	r_surf.o	\
	r_2d.o

SERVER_OBJS = 		\
	pr_cmds.o 		\
	pr_q1qvm.o	\
	pr_lua.o	\
	sv_master.o 	\
	sv_init.o 		\
	sv_main.o 		\
	sv_nchan.o 		\
	sv_ents.o 		\
	sv_send.o 		\
	sv_user.o		\
	sv_sql.o		\
	sv_mvd.o		\
	sv_ccmds.o 		\
	sv_cluster.o		\
	sv_rankin.o 	\
	sv_chat.o 		\
	sv_demo.o		\
	net_preparse.o 	\
	savegame.o		\
	svq2_ents.o 	\
	svq2_game.o 	\
	webgen.o		\
	ftpserver.o		\
	httpserver.o

Q3_OBJS = clq3_parse.o	\
		clq3_ui.o	\
		clq3_cg.o 	\
		svq3_game.o	\
		q3common.o	\
		be_aas_bspq3.o		\
		be_aas_cluster.o	\
		be_aas_debug.o		\
		be_aas_entity.o		\
		be_aas_file.o		\
		be_aas_main.o		\
		be_aas_move.o		\
		be_aas_optimize.o	\
		be_aas_reach.o		\
		be_aas_route.o		\
		be_aas_routealt.o	\
		be_aas_sample.o		\
		be_ai_char.o		\
		be_ai_chat.o		\
		be_ai_gen.o		\
		be_ai_goal.o		\
		be_ai_move.o		\
		be_ai_weap.o		\
		be_ai_weight.o		\
		be_ea.o			\
		be_interface.o		\
		l_crc.o			\
		l_libvar.o		\
		l_log.o			\
		l_memory.o		\
		l_precomp.o		\
		l_script.o		\
		l_struct.o	

EXTRA_OBJS = \
	dll_ctr.o \
	gl_vid3ds.o \
	cd_null.o \
	in_3ds.o
#	vid_ctr.o
#	snd_ctr.o TODO snd
#	in_ctr.o TODO input

SV_CFLAGS=$(SERVER_ONLY_CFLAGS) $(W32_CFLAGS)

#GL_LDFLAGS=$(GLLDFLAGS) #-landroid
GLCL_OBJS=$(GL_OBJS) $(D3DGL_OBJS)

FINAL_OBJS=$(COMMON_OBJS) $(CLIENT_OBJS) $(PROGS_OBJS) $(GLCL_OBJS) $(SERVER_OBJS) $(GLQUAKE_OBJS) $(D3DGL_OBJS) $(Q3_OBJS) $(EXTRA_OBJS) sys_3ds.o

#---------------------------------------------------------------------------------
.SUFFIXES:
#---------------------------------------------------------------------------------

ifeq ($(strip $(DEVKITARM)),)
$(error "Please set DEVKITARM in your environment. export DEVKITARM=<path to>devkitARM")
endif

TOPDIR ?= $(CURDIR)
include $(DEVKITARM)/3ds_rules

#---------------------------------------------------------------------------------
# TARGET is the name of the output
# BUILD is the directory where object files & intermediate files will be placed
# SOURCES is a list of directories containing source code
# DATA is a list of directories containing data files
# INCLUDES is a list of directories containing header files
# GRAPHICS is a list of directories containing graphics files
# GFXBUILD is the directory where converted graphics files will be placed
#   If set to $(BUILD), it will statically link in the converted
#   files as if they were data files.
#
# NO_SMDH: if set to anything, no SMDH file is generated.
# ROMFS is the directory which contains the RomFS, relative to the Makefile (Optional)
# APP_TITLE is the name of the app stored in the SMDH file (Optional)
# APP_DESCRIPTION is the description of the app stored in the SMDH file (Optional)
# APP_AUTHOR is the author of the app stored in the SMDH file (Optional)
# ICON is the filename of the icon (.png), relative to the project folder.
#   If not set, it attempts to use one of the following (in this order):
#     - <Project name>.png
#     - icon.png
#     - <libctru folder>/default_icon.png
#---------------------------------------------------------------------------------
TARGET		:=	$(notdir $(CURDIR))
BUILD		:=	build
SOURCES		:=	include client common d3d gl http qclib server sw vk web  platform platform/ctr ../plugins/quake3 ../plugins/quake3/botlib
DATA		:=	platform/ctr/assets
INCLUDES	:=	include client common d3d gl http qclib server sw vk web  platform platform/ctr ../plugins/quake3 ../plugins/quake3/botlib
GRAPHICS	:=	gfx
GFXBUILD	:=	$(BUILD)
#ROMFS		:=	romfs

APP_TITLE	:=  FTEQW
APP_DESCRIPTION := FTEQW 3DS fork
APP_AUTHOR  := seicore
ICON 		:= icon.png

#---------------------------------------------------------------------------------
# options for code generation
#---------------------------------------------------------------------------------
ARCH	:=	-march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft

CFLAGS	:=	-Wall -O2 -ffast-math -mword-relocations \
			-fomit-frame-pointer -ffunction-sections \
			-fdata-sections -fno-short-enums $(ARCH)

CFLAGS	+=	$(INCLUDE) -D__3DS__ -DSINGLE_BINARY -DGLQUAKE -DNO_GNUTLS -DLIBJPEG_STATIC -DLIBJPEG_STATIC -DLIBPNG_STATIC -DOPUS_STATIC -DSPEEX_STATIC -DFREETYPE_STATIC -DLIBVORBISFILE_STATIC -DOPENAL_STATIC -DGL_STATIC -DZLIB_STATIC -DGNUTLS_STATIC -DSTATIC_Q3 -DBOTLIB -DBOTLIB_STATIC -DLINK_QUAKE3 -DQ3_LITTLE_ENDIAN -O2 -Os

#---------------------------------------------------------------------------------
# build errors, todo investigate
#---------------------------------------------------------------------------------
CFLAGS  +=  --warn-no-implicit-function-declaration --warn-no-incompatible-pointer-types --warn-no-return-mismatch --warn-no-int-conversion


CXXFLAGS	:= $(CFLAGS) -fno-rtti -fno-exceptions -std=gnu++11

ASFLAGS	:=	-g $(ARCH)
LDFLAGS	=	-specs=3dsx.specs -g $(ARCH) -Wl,-Map,$(notdir $*.map),--allow-multiple-definition

LIBS	:=  -lpicaGL -lctru -lm -lstdc++ -lfreetype -ljpeg -lvorbisidec -logg -lz -lgltf -lpng -lbz2

#---------------------------------------------------------------------------------
# list of directories containing libraries, this must be the top level containing
# include and lib
#---------------------------------------------------------------------------------
LIBDIRS	:= $(CTRULIB) $(DEVKITPRO)/portlibs/3ds $(CURDIR)/picaGL $(CURDIR)


#---------------------------------------------------------------------------------
# no real need to edit anything past this point unless you need to add additional
# rules for different file extensions
#---------------------------------------------------------------------------------
ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------

export OUTPUT	:=	$(CURDIR)/$(TARGET)
export TOPDIR	:=	$(CURDIR)

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
			$(foreach dir,$(GRAPHICS),$(CURDIR)/$(dir)) \
			$(foreach dir,$(DATA),$(CURDIR)/$(dir))

export DEPSDIR	:=	$(CURDIR)/$(BUILD)

CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
PICAFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.v.pica)))
SHLISTFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.shlist)))
GFXFILES	:=	$(foreach dir,$(GRAPHICS),$(notdir $(wildcard $(dir)/*.t3s)))
BINFILES	:=	$(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))

#---------------------------------------------------------------------------------
# use CXX for linking C++ projects, CC for standard C
#---------------------------------------------------------------------------------
ifeq ($(strip $(CPPFILES)),)
#---------------------------------------------------------------------------------
	export LD	:=	$(CC)
#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
	export LD	:=	$(CXX)
#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
ifeq ($(GFXBUILD),$(BUILD))
#---------------------------------------------------------------------------------
export T3XFILES :=  $(GFXFILES:.t3s=.t3x)
#---------------------------------------------------------------------------------
else
#---------------------------------------------------------------------------------
export ROMFS_T3XFILES	:=	$(patsubst %.t3s, $(GFXBUILD)/%.t3x, $(GFXFILES))
export T3XHFILES		:=	$(patsubst %.t3s, $(BUILD)/%.h, $(GFXFILES))
#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------

export OFILES_SOURCES 	:=	$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) $(SFILES:.s=.o)

export OFILES_BIN	:=	$(addsuffix .o,$(BINFILES)) \
			$(PICAFILES:.v.pica=.shbin.o) $(SHLISTFILES:.shlist=.shbin.o) \
			$(addsuffix .o,$(T3XFILES))

#export OFILES := $(OFILES_BIN) $(OFILES_SOURCES)
export OFILES := $(OFILES_BIN) $(FINAL_OBJS)

export HFILES	:=	$(PICAFILES:.v.pica=_shbin.h) $(SHLISTFILES:.shlist=_shbin.h) \
			$(addsuffix .h,$(subst .,_,$(BINFILES))) \
			$(GFXFILES:.t3s=.h)

export INCLUDE	:=	$(foreach dir,$(INCLUDES),-I$(CURDIR)/$(dir)) \
			$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
			-I$(CURDIR)/$(BUILD) \
			-I$(DEVKITPRO)/portlibs/3ds/include/freetype2 \
			-I$(CURDIR)/picaGL/include/GL \
			-I$(CURDIR)/../plugins

export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L$(dir)/lib)

export _3DSXDEPS	:=	$(if $(NO_SMDH),,$(OUTPUT).smdh)

ifeq ($(strip $(ICON)),)
	icons := $(wildcard *.png)
	ifneq (,$(findstring $(TARGET).png,$(icons)))
		export APP_ICON := $(TOPDIR)/$(TARGET).png
	else
		ifneq (,$(findstring icon.png,$(icons)))
			export APP_ICON := $(TOPDIR)/icon.png
		endif
	endif
else
	export APP_ICON := $(TOPDIR)/$(ICON)
endif

ifeq ($(strip $(NO_SMDH)),)
	export _3DSXFLAGS += --smdh=$(CURDIR)/$(TARGET).smdh
endif

ifneq ($(ROMFS),)
	export _3DSXFLAGS += --romfs=$(CURDIR)/$(ROMFS)
endif

.PHONY: all clean

#---------------------------------------------------------------------------------
all: $(BUILD) $(GFXBUILD) $(DEPSDIR) $(ROMFS_T3XFILES) $(T3XHFILES)
	@$(MAKE) --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

cia: $(OUTPUT).elf
	@makerom -f cia -o $(OUTPUT).cia -elf $(OUTPUT).elf -rsf cia.rsf -banner banner.bnr -icon $(OUTPUT).smdh -target t
	@echo built ... $(notdir $@)

$(BUILD):
	@mkdir -p $@

ifneq ($(GFXBUILD),$(BUILD))
$(GFXBUILD):
	@mkdir -p $@
endif

ifneq ($(DEPSDIR),$(BUILD))
$(DEPSDIR):
	@mkdir -p $@
endif

#---------------------------------------------------------------------------------
clean:
	@echo clean ...
	@rm -fr $(BUILD) $(TARGET).3dsx $(OUTPUT).smdh $(TARGET).elf $(GFXBUILD)

clean_submodules: clean
	$(MAKE) -C hlsdk_3ds clean
	$(MAKE) -C mainui_3ds clean
	$(MAKE) -C picaGL clean

#---------------------------------------------------------------------------------
$(GFXBUILD)/%.t3x	$(BUILD)/%.h	:	%.t3s
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@tex3ds -i $< -H $(BUILD)/$*.h -d $(DEPSDIR)/$*.d -o $(GFXBUILD)/$*.t3x

#---------------------------------------------------------------------------------
else

#---------------------------------------------------------------------------------
# main targets
#---------------------------------------------------------------------------------
$(OUTPUT).3dsx	:	$(OUTPUT).elf $(_3DSXDEPS)

$(OFILES_SOURCES) : $(HFILES)

$(OUTPUT).elf	:	$(OFILES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OFILES) $(LIBPATHS) $(LIBS) -o $@

#---------------------------------------------------------------------------------
# you need a rule like this for each extension you use as binary data
#---------------------------------------------------------------------------------
%.bin.o	%_bin.h :	%.bin
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#---------------------------------------------------------------------------------
.PRECIOUS	:	%.t3x
#---------------------------------------------------------------------------------
%.t3x.o	%_t3x.h :	%.t3x
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@$(bin2o)

#---------------------------------------------------------------------------------
# rules for assembling GPU shaders
#---------------------------------------------------------------------------------
define shader-as
	$(eval CURBIN := $*.shbin)
	$(eval DEPSFILE := $(DEPSDIR)/$*.shbin.d)
	echo "$(CURBIN).o: $< $1" > $(DEPSFILE)
	echo "extern const u8" `(echo $(CURBIN) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"_end[];" > `(echo $(CURBIN) | tr . _)`.h
	echo "extern const u8" `(echo $(CURBIN) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`"[];" >> `(echo $(CURBIN) | tr . _)`.h
	echo "extern const u32" `(echo $(CURBIN) | sed -e 's/^\([0-9]\)/_\1/' | tr . _)`_size";" >> `(echo $(CURBIN) | tr . _)`.h
	picasso -o $(CURBIN) $1
	bin2s $(CURBIN) | $(AS) -o $*.shbin.o
endef

%.shbin.o %_shbin.h : %.v.pica %.g.pica
	@echo $(notdir $^)
	@$(call shader-as,$^)

%.shbin.o %_shbin.h : %.v.pica
	@echo $(notdir $<)
	@$(call shader-as,$<)

%.shbin.o %_shbin.h : %.shlist
	@echo $(notdir $<)
	@$(call shader-as,$(foreach file,$(shell cat $<),$(dir $<)$(file)))

#---------------------------------------------------------------------------------
%.t3x	%.h	:	%.t3s
#---------------------------------------------------------------------------------
	@echo $(notdir $<)
	@tex3ds -i $< -H $*.h -d $*.d -o $*.t3x

-include $(DEPSDIR)/*.d

#---------------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------------