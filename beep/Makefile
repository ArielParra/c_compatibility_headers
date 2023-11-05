ifdef OS  #Windows OS Detection
	CC := gcc.exe
	FLAGS := -lwinmm
	RM := del /Q
	FixPath = $(subst /,\,$1)
	UNAME := Windows
	EXT := .exe
else  	  #*NIX using GNU make
	CC := gcc
	FLAGS := -lncurses
	RM := rm -f 
	FixPath = $1
	UNAME = $(shell uname)
	EXT :=
	ifeq ($(UNAME),Darwin) #MacOS
		FLAGS = -framework AudioUnit
	endif
	ifeq ($(UNAME),Linux) #Linux
		FLAGS = -lasound
	endif
endif

CFLAGS := -O2 -s -Wall

Name1 := beep-$(UNAME)
Name2 := mario-$(UNAME)
Name3 := jingleBell-$(UNAME)

all: $(Name1) $(Name2) $(Name3)

$(Name1): beep.c beep.h
	$(CC) -o $(call FixPath,$(Name1)) $< $(FLAGS) $(CFLAGS)

$(Name2): beep_mario.c beep.h
	$(CC) -o $(call FixPath,$(Name2)) $< $(FLAGS) $(CFLAGS)

$(Name3): beep_jingleBell.c beep.h
	$(CC) -o $(call FixPath,$(Name3)) $< $(FLAGS) $(CFLAGS)

clean:
	$(RM) $(call FixPath,$(Name1)$(EXT))
	$(RM) $(call FixPath,$(Name2)$(EXT))
	$(RM) $(call FixPath,$(Name3)$(EXT))
