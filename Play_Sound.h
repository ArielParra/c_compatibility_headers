#ifndef Play_Sound_h
#define Play_Sound_h

#ifdef __cplusplus
extern "C" {
#endif

/*Shared C libraries*/
#include<stdlib.h>//system()
#include<string.h>//strcat(),strcpy(),strlen()

/*OS detection*/
#if defined(_WIN32) || defined(_CYGWIN_)

    #include <windows.h>//PlaySound() need -lwinmm as compiler argument
    void Play_Sound(const char* file){PlaySound(TEXT(file),NULL,SND_ASYNC);}//qSound will stop while using getch()
    void Stop_Sound(){PlaySound(NULL, 0, 0);}

    /*using sox.exe from: https://sourceforge.net/projects/sox/ */
    //void Play_Sound(const char* file){char SoundCommand[strlen(file)+24+11];strcpy(SoundCommand, "sox.exe -t waveaudio -d ");strcat(SoundCommand, file);strcat(SoundCommand,">NUL 2>&1 &");system(SoundCommand);}
    //void Stop_Sound(){system("taskkill /F /IM sox.exe");}


#elif defined(__linux__)

    void Play_Sound(const char* file){char SoundCommand[strlen(file)+6+17];strcpy(SoundCommand, "aplay ");strcat(SoundCommand, file);strcat(SoundCommand,">/dev/null 2>&1 &");system(SoundCommand);}
    void Stop_Sound(){system("pkill aplay");}

#elif defined(__APPLE__) || defined(__MACH__)
    
    void Play_Sound(const char* file){char SoundCommand[strlen(file)+7+17];strcpy(SoundCommand, "afplay ");strcat(SoundCommand, file);strcat(SoundCommand,">/dev/null 2>&1 &");system(SoundCommand);}
    void Stop_Sound(){system("pkill afplay");}

#elif defined(__OpenBSD__)

    void Play_Sound(const char* file){char SoundCommand[strlen(file)+9+17];strcpy(SoundCommand, "aucat -i ");strcat(SoundCommand, file);strcat(SoundCommand,">/dev/null 2>&1 &");system(SoundCommand);}
    void Stop_Sound(){system("pkill aucat");}

#else //other *NIX using a bash shell
    
    /*having the sox package to use the play command*/
    void Play_Sound(const char* file){char SoundCommand[strlen(file)+14+18];strcpy(SoundCommand, "bash -c 'play ");strcat(SoundCommand, file);strcat(SoundCommand,">/dev/null 2>&1 &'");system(SoundCommand);}
    void Stop_Sound(){system("pkill play");}

    /*having the ffmpeg package to use the ffplay command*/
    //void Play_Sound(const char* file){char SoundCommand[strlen(file)+24+18];strcpy(SoundCommand, "bash -c 'ffplay -nodisp ");strcat(SoundCommand, file);strcat(SoundCommand,">/dev/null 2>&1 &'");system(SoundCommand);}
    //void Stop_Sound(){system("pkill ffplay");}

#endif//OS detection 

#ifdef __cplusplus
}
#endif//__cplusplus

# endif//Play_Sound_h
