#ifndef windowsCompat_h 
#define windowsCompat_h 

#ifndef __GNUC__
    #warning "You do not have the Gnu C Compiler (GCC)"
#endif

#ifdef __clang__
    #warning "Clang compiler is being used"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*Shared C libraries | START*/
#include <stdlib.h>//system()
#include <string.h>//strcat(),strcpy(),strlen()
/*Shared C libraries | END*/

#if defined(_WIN32) || defined(_CYGWIN_)/*OS detection | START*/

    #include <windows.h>//strrev()
    #include <synchapi.h>//Sleep()

#else //*NIX

    #include<unistd.h>//usleep()

    /*Windows Specific data types | START*/
    #define WINAPI
    #define TCHAR char*
    #define WCHAR char*
    #define DWORD unsigned long
    #define HANDLE void*
    #define PATH_MAX MAX_PATH
    #define BYTE unsigned char
    #define WORD unsigned short1
    #define BOOL unsigned int
    /*Windows Specific data types | END*/

    void Sleep(unsigned int ms){usleep(ms*1000);}
    
    #include<stdio.h>//printf()
    int SetConsoleTitle(const char *str){ printf("\033]0;%s\007",str);return 0; }
    #define SetConsoleTitleA SetConsoleTitle
    char *strrev(char *str){
        char *p1,*p2;
        if(! str || ! *str) return str;
        for(p1=str,p2=str+strlen(str)-1;p2>p1;++p1,--p2){
            *p1^=*p2;*p2^=*p1;*p1^=*p2;
        }
    return str;
    }

#endif/*OS detection | END*/

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//windowsCompat_h 
