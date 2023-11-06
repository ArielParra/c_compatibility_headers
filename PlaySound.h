#ifndef PlaySound_h 
#define PlaySound_h 

#ifndef __GNUC__
    #warning "You do not have the Gnu C Compiler (GCC)"
#endif

#ifdef __clang__
    #warning "Clang compiler is being used"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*OS detection*/
#if defined(_WIN32) || defined(_CYGWIN_)

    #include <windows.h>//PlaySound()

    //#pragma comment(lib, "winmm") //Microsoft Visual C++ (MSVC) specific macro
    //void Play_Sound(const char* file){PlaySound(TEXT(file),NULL,SND_ASYNC);}//PlaySound() will stop while using getch()
    
    #warning "PlaySound() needs -lwinmm as compiler argument"

    DWORD WINAPI ThreadFunction(LPVOID lpParameter){
        const char* file = (const char*)lpParameter;
        PlaySoundA(file, NULL, SND_ASYNC);
        return 0; 
    }
    #include<stdio.h>//fprintf(),stderr
    void Play_Sound(const char* file){
        HANDLE hThread = CreateThread(NULL, 0, ThreadFunction, (LPVOID)file, 0, NULL);
        if (!hThread) {fprintf(stderr, "Failed to create Play_Sound() thread.\n");exit(1);}
    }//Play_Sound() will not stop while using getch()
    void Stop_Sound(){ PlaySound(NULL, 0, 0); }

    /* Using sox or ffmpeg ffplay apps, 
    sox.exe needs 14 dlls to work and only uses 4.96MB in total, 
    ffplay.exe is a standalon exe without dlls, but it is 77.2MB in size,
    You can get sox portable from: https://sourceforge.net/projects/sox/files/sox/14.4.2/sox-14.4.2-win32.zip/download
    You can get ffmpeg portable from: https://www.gyan.dev/ffmpeg/builds/ffmpeg-git-essentials.7z
    
    Carefull with the music file routes on Windows, you need two backslashes per backslash 
    in the system() function. Might work wiht normal slashes in newer Windows using pwsh, 
    but may use convertToWindowsRoute() function for compatibility in cmd

    If you modify the SoundCommand,please modify the string size 
    */
    /*
    void convertToWindowsRoute(char* str) {
        for (size_t i = 0; i < strlen(str); i++)
            if (str[i] == '/') str[i] = '\\';
    }
    */ 
    /*
    void Play_Sound(const char* file){
        convertToWindowsRoute(file);
        const char SoundCommand[strlen(file)+23+28];strcpy(SoundCommand, "start /b .\\sox.exe .\\");
        strcat(SoundCommand, file);strcat(SoundCommand," -t waveaudio -d >NUL 2>&1 &");system(SoundCommand);
    }
    void Stop_Sound(){system("taskkill /F /IM sox.exe >NUL 2>&1 &");}
    */
    /*
    void Play_Sound(const char* file){
        convertToWindowsRoute(file);
        const char SoundCommand[strlen(file)+34+11];strcpy(SoundCommand, "start /b .\\ffplay.exe -nodisp .\\");
        strcat(SoundCommand, file);strcat(SoundCommand,">NUL 2>&1 &");system(SoundCommand);
    }
    void Stop_Sound(){system("taskkill /F /IM ffplay.exe >NUL 2>&1 &");}
    */
#elif defined(__unix__)|| defined(__APPLE__) || defined(__MACH__) //*NIX

    #if defined(__linux__)

        #include <stdlib.h>//getenv()
        
        //If you are on WSL, you need ffmpeg package to use Play_Sound()
        void Play_Sound(const char* file){
            char SoundCommand[strlen(file)+15+17];
            if (getenv("WSL_DISTRO_NAME")) strcpy(SoundCommand, "ffplay -nodisp ");
            else strcpy(SoundCommand, "aplay ");
            strcat(SoundCommand, file);
            strcat(SoundCommand,">/dev/null 2>&1 &");
            system(SoundCommand);
        }
        void Stop_Sound(){
            if (getenv("WSL_DISTRO_NAME")) system("pkill ffplay >/dev/null 2>&1 &");
            else system("pkill aplay >/dev/null 2>&1 &");
        }
    
    #elif defined(__APPLE__) || defined(__MACH__)
        
        void Play_Sound(const char* file){
            char SoundCommand[strlen(file)+7+17];
            strcpy(SoundCommand, "afplay ");strcat(SoundCommand, file);
            strcat(SoundCommand,">/dev/null 2>&1 &");system(SoundCommand);
        }
        void Stop_Sound(){system("pkill afplay >/dev/null 2>&1 &");}

    #elif defined(__OpenBSD__)

        void Play_Sound(const char* file){
            char SoundCommand[strlen(file)+9+17];
            strcpy(SoundCommand, "aucat -i ");strcat(SoundCommand, file);
            strcat(SoundCommand,">/dev/null 2>&1 &");system(SoundCommand);
        }
        void Stop_Sound(){system("pkill aucat >/dev/null 2>&1 &");}

    #else //other *NIX using a bash shell
        
        /*having the */
        #warning  "To use Play_Sound you need the sox package"
        void Play_Sound(const char* file){
            char SoundCommand[strlen(file)+14+18];
            strcpy(SoundCommand, "bash -c 'play ");strcat(SoundCommand, file);
            strcat(SoundCommand,">/dev/null 2>&1 &'");system(SoundCommand);
            }
        void Stop_Sound(){system("bash -c 'pkill play >/dev/null 2>&1 &'");}

        /*having the ffmpeg package to use the ffplay command*/
        /*
        void Play_Sound(const char* file){
            char SoundCommand[strlen(file)+24+18];
            strcpy(SoundCommand, "bash -c 'ffplay -nodisp ");strcat(SoundCommand, file);
            strcat(SoundCommand,">/dev/null 2>&1 &'");system(SoundCommand);
        }
        void Stop_Sound(){system("bash -c 'pkill ffplay >/dev/null 2>&1 &'");}
        */
    #endif 
#endif//OS detection 

#ifdef PlaySoundA
    #undef PlaySoundA
#endif
#define PlaySoundA(file, hmod, fdwSound) do{ \
    if(file==NULL) Stop_Sound();\
    else Play_Sound(file);\
    }while(0)

#ifdef PlaySound
    #undef PlaySound
#endif
#define PlaySound PlaySoundA
#ifdef __cplusplus
}
#endif//__cplusplus

#endif//PlaySound_h 

