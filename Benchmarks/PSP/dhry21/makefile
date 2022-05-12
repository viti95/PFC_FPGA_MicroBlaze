TARGET = dhry21
OBJS = $(SOURCES:.c=.o)
SOURCES= dhry_1.c dhry_2.c

INCDIR =
CFLAGS = -O3 -g -Wall -fomit-frame-pointer -march=allegrex -mtune=allegrex
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBS = -lpsppower

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Dhrystone 2.1

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
