TARGET = whets
OBJS = $(SOURCES:.c=.o)
SOURCES= whetstone.c

INCDIR =
CFLAGS = -O3 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBS = -lpsppower -lm -lpspmath

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Whetstone VFPU

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
