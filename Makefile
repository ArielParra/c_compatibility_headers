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
endif

CFLAGS := -O2 -s -Wall

Name1 := example-stdlibCompat-$(UNAME)
Name2 := example-playSound-$(UNAME)
Name3 := example-ansiCompat-$(UNAME)
Name4 := example-ncursesCompat-$(UNAME)
Name5 := example-allCompat-$(UNAME)

all: $(Name1) $(Name2) $(Name3) $(Name4) $(Name5)

$(Name1): stdlibExample.c stdlibCompat.h
	$(CC) -o $(call FixPath,$(Name1)) $< $(FLAGS) $(CFLAGS)

$(Name2): PlaySoundExample.c PlaySound.h windowsCompat.h
	$(CC) -o $(call FixPath,$(Name2)) $< $(FLAGS) $(CFLAGS)

$(Name3): ansiExample.c ansiCompat.h stdlibCompat.h
	$(CC) -o $(call FixPath,$(Name3)) $< $(FLAGS) $(CFLAGS)

$(Name4): ncursesExample.c ncursesCompat.h stdlibCompat.h
	$(CC) -o $(call FixPath,$(Name4)) $< $(FLAGS) $(CFLAGS)

$(Name5): allExample.c allCompat.h
	$(CC) -o $(call FixPath,$(Name5)) $< $(FLAGS) $(CFLAGS)

clean:
	$(RM) $(call FixPath,$(Name1)$(EXT))
	$(RM) $(call FixPath,$(Name2)$(EXT))
	$(RM) $(call FixPath,$(Name3)$(EXT))
	$(RM) $(call FixPath,$(Name4)$(EXT))
	$(RM) $(call FixPath,$(Name5)$(EXT))
	$(RM) $(call FixPath,a.exe)
	$(RM) $(call FixPath,a.out)