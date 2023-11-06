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

Name1 := example-stdlibCompat-$(UNAME)
Name2 := example-playSound-$(UNAME)
Name3 := example-ansiCompat-$(UNAME)
Name4 := example-ncursesCompat-$(UNAME)
Name5 := example-ncursesColor-$(UNAME)
Name6 := example-conioCompat-$(UNAME)
Name7 := example-windowsCompat-$(UNAME)
Name8 := example-allCompat-$(UNAME)


all: $(Name1) $(Name2) $(Name3) $(Name4) $(Name5) $(Name6) $(Name7) $(Name8)

$(Name1): stdlibExample.c stdlib.h
	$(CC) -o $(call FixPath,$(Name1)) $< $(FLAGS) $(CFLAGS)

$(Name2): PlaySoundExample.c PlaySound.h windows.h
	$(CC) -o $(call FixPath,$(Name2)) $< $(FLAGS) $(CFLAGS)

$(Name3): ansiExample.c ansi.h stdlib.h windows.h
	$(CC) -o $(call FixPath,$(Name3)) $< $(FLAGS) $(CFLAGS)

$(Name4): ncursesExample.c ncurses.h
	$(CC) -o $(call FixPath,$(Name4)) $< $(FLAGS) $(CFLAGS)

$(Name5): ncursesColorExample.c ncursesColor.h
	$(CC) -o $(call FixPath,$(Name5)) $< $(FLAGS) $(CFLAGS)

$(Name6): conioExample.c conio.h
	$(CC) -o $(call FixPath,$(Name6)) $< $(FLAGS) $(CFLAGS)

$(Name7): windowsExample.c windows.h
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
