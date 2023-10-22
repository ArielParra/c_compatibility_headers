ifdef OS  #Windows OS Detection
	CC = gcc.exe
	FLAGS = -lwinmm
	RM = del /Q
	FixPath = $(subst /,\,$1)
else  	  #*NIX using GNU make
	CC = gcc
	FLAGS = -lncurses
	RM = rm -f 
	FixPath = $1
endif

CFLAGS = -O2 -s

Name1 = example-stdlibCompat
Name2 = example-play_Sound
Name3 = example-ansiCompat
Name4 = example-ncursesCompat
Name5 = example-allCompat

all: $(Name1) $(Name2) $(Name3) $(Name4) $(Name5)

$(Name1): stdlibExample.c stdlibCompat.h
	$(CC) -o $(call FixPath,$(Name1)) $< $(FLAGS) $(CFLAGS)

$(Name2): Play_SoundExample.c Play_Sound.h stdlibCompat.h
	$(CC) -o $(call FixPath,$(Name2)) $< $(FLAGS) $(CFLAGS)

$(Name3): ansiExample.c ansiCompat.h stdlibCompat.h
	$(CC) -o $(call FixPath,$(Name3)) $< $(FLAGS) $(CFLAGS)

$(Name4): ncursesExample.c ncursesCompat.h stdlibCompat.h
	$(CC) -o $(call FixPath,$(Name4)) $< $(FLAGS) $(CFLAGS)

$(Name5): allExample.c allCompat.h
	$(CC) -o $(call FixPath,$(Name5)) $< $(FLAGS) $(CFLAGS)

clean:
ifdef OS
	$(RM) $(call FixPath,$(Name1).exe)
	$(RM) $(call FixPath,$(Name2).exe)
	$(RM) $(call FixPath,$(Name3).exe)
	$(RM) $(call FixPath,$(Name4).exe)
	$(RM) $(call FixPath,$(Name5).exe)
	$(RM) $(call FixPath,a.exe)
else
	$(RM) $(call FixPath,$(Name1))
	$(RM) $(call FixPath,$(Name2))
	$(RM) $(call FixPath,$(Name3))
	$(RM) $(call FixPath,$(Name4))
	$(RM) $(call FixPath,$(Name5))
	$(RM) $(call FixPath,a.out)
endif

