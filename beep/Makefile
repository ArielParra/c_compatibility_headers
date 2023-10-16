ifdef OS #Windows
	CC = gcc.exe
	FLAGS = -lwinmm
	RM = del /Q
else
	CC = gcc
	RM = rm -f 
	FixPath = $1
	ifeq ($(shell uname),Darwin) #MacOS
		FLAGS = -framework AudioUnit
	endif
	ifeq ($(shell uname),Linux) #Linux
		FLAGS = -lasound
	endif
endif

CFLAGS = -O2 -s

Name1 = beep
Name2 = mario
Name3 = jingleBell

all: $(Name1) $(Name2) $(Name3)

$(Name1): beep.c beep.h
	$(CC) -o $(call FixPath,$(Name1)) $< $(FLAGS) $(CFLAGS)

$(Name2): beep_mario.c beep.h
	$(CC) -o $(call FixPath,$(Name2)) $< $(FLAGS) $(CFLAGS)

$(Name3): beep_jingleBell.c beep.h
	$(CC) -o $(call FixPath,$(Name3)) $< $(FLAGS) $(CFLAGS)

clean:
	$(RM) $(call FixPath,$(Name1).exe)
	$(RM) $(call FixPath,$(Name1))
	$(RM) $(call FixPath,$(Name2).exe)
	$(RM) $(call FixPath,$(Name2))
	$(RM) $(call FixPath,$(Name3).exe)
	$(RM) $(call FixPath,$(Name3))
	$(RM) $(call FixPath,a.exe)
	$(RM) $(call FixPath,a.out)
