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

CFLAGS := -O2 -s -w
OUTPUT_DIR := examples

Name1 := $(OUTPUT_DIR)/example-stdlibCompat-$(UNAME)
Name2 := $(OUTPUT_DIR)/example-playSound-$(UNAME)
Name3 := $(OUTPUT_DIR)/example-ansiCompat-$(UNAME)
Name4 := $(OUTPUT_DIR)/example-ncursesCompat-$(UNAME)
Name5 := $(OUTPUT_DIR)/example-ncursesColor-$(UNAME)
Name6 := $(OUTPUT_DIR)/example-conioCompat-$(UNAME)
Name7 := $(OUTPUT_DIR)/example-windowsCompat-$(UNAME)
Name8 := $(OUTPUT_DIR)/example-allCompat-$(UNAME)

all: $(Name1) $(Name2) $(Name3) $(Name4) $(Name5) $(Name6) $(Name7) $(Name8)

$(Name1): stdlib_h/stdlibExample.c stdlib_h/stdlib.h
	$(CC) -o $(call FixPath,$(Name1)) $< $(FLAGS) $(CFLAGS)

$(Name2): windows_h/PlaySoundExample.c windows_h/PlaySound.h windows_h/windows.h
	$(CC) -o $(call FixPath,$(Name2)) $< $(FLAGS) $(CFLAGS)

$(Name3): ansi/ansiExample.c ansi/ansi.h stdlib_h/stdlib.h windows_h/windows.h
	$(CC) -o $(call FixPath,$(Name3)) $< $(FLAGS) $(CFLAGS)

$(Name4): ncurses_h/ncursesExample.c ncurses_h/ncurses.h
	$(CC) -o $(call FixPath,$(Name4)) $< $(FLAGS) $(CFLAGS)

$(Name5): ncurses_h/ncursesColorExample.c ncurses_h/ncursesColor.h
	$(CC) -o $(call FixPath,$(Name5)) $< $(FLAGS) $(CFLAGS)

$(Name6): conio_h/conioExample.c conio_h/conio.h
	$(CC) -o $(call FixPath,$(Name6)) $< $(FLAGS) $(CFLAGS)

$(Name7): windows_h/windowsExample.c windows_h/windows.h
	$(CC) -o $(call FixPath,$(Name7)) $< $(FLAGS) $(CFLAGS)

$(Name8): allExample.c allCompat.h
	$(CC) -o $(call FixPath,$(Name8)) $< $(FLAGS) $(CFLAGS)

clean:
	$(RM) $(call FixPath,$(Name1)$(EXT))
	$(RM) $(call FixPath,$(Name2)$(EXT))
	$(RM) $(call FixPath,$(Name3)$(EXT))
	$(RM) $(call FixPath,$(Name4)$(EXT))
	$(RM) $(call FixPath,$(Name5)$(EXT))
	$(RM) $(call FixPath,$(Name6)$(EXT))
	$(RM) $(call FixPath,$(Name7)$(EXT))
	$(RM) $(call FixPath,$(Name8)$(EXT))
	$(RM) $(call FixPath,a.exe)
	$(RM) $(call FixPath,a.out)