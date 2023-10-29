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

    /* Warnings!
    Carefull with the windows routes, you need four backslashes per backslash in the system() function.
    Might work wihtout backlashes in newer Windows, but may need them for retrocompatibility in cmd
    If you modify the SoundCommand,please modify the string size 
    */

    #include <windows.h>//PlaySound() need -lwinmm as compiler argument
    
    //void Play_Sound(const char* file){PlaySound(TEXT(file),NULL,SND_ASYNC);}//PlaySound() will stop while using getch()

    DWORD WINAPI ThreadFunction(LPVOID lpParameter) {
    const char* file = (const char*)lpParameter;
    PlaySoundA(file, NULL, SND_ASYNC); 
    return 0;
    }
    #include<stdio.h>//fprintf(),stderr
    void Play_Sound(const char* file) {
	HANDLE hThread = CreateThread(NULL, 0, ThreadFunction, (LPVOID)file, 0, NULL);
    if (!hThread) {fprintf(stderr, "Failed to create Play_Sound() thread.\n");exit(1);}
    }//Play_Sound() will not stop while using getch()
    void Stop_Sound(){PlaySound(NULL, 0, 0);}

    /* Using sox or ffmpeg ffplay command, 
    sox.exe needs 14 dlls to work and only uses 4.96MB in total, 
    ffplay.exe is standalon without dlls, but it is 77.2MB in size,
    You can get sox portable from: https://sourceforge.net/projects/sox/files/sox/14.4.2/sox-14.4.2-win32.zip/download
    You can get ffmpeg portable from: https://www.gyan.dev/ffmpeg/builds/ffmpeg-git-essentials.7z
    */

    //void Play_Sound(const char* file){char SoundCommand[strlen(file)+27+28];strcpy(SoundCommand, "start /b .\\\\sox.exe .\\\\");strcat(SoundCommand, file);strcat(SoundCommand," -t waveaudio -d >NUL 2>&1 &");system(SoundCommand);}
    //void Stop_Sound(){system("taskkill /F /IM sox.exe");}
    
    //void Play_Sound(const char* file){char SoundCommand[strlen(file)+38+11];strcpy(SoundCommand, "start /b .\\\\ffplay.exe -nodisp .\\\\");strcat(SoundCommand, file);strcat(SoundCommand,">NUL 2>&1 &");system(SoundCommand);}
    //void Stop_Sound(){system("taskkill /F /IM ffplay.exe");}

#elif defined(__linux__)

    //*WSL Linux needs ffplay command from ffmpeg
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
