#ifndef windowsCompat_h 
#define windowsCompat_h 

#ifndef __GNUC__
#warning "You are not using Gnu C Compiler (GCC)"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
    #include<windows.h>
    #include<synchapi.h>//Sleep()

void setTitle(){}

#else//*NIX

    #include<unistd.h>//usleep()
    #define TCHAR char *str
    void Sleep(unsigned int ms){usleep(ms*1000);}
    int SetConsoleTitle(const char *str){printf("\033]0;%s\007",str); return 0;}
    #define SetConsoleTitleA SetConsoleTitle
    char *strrev(char *str){
        char *p1,*p2;
        if (! str || ! *str)
            return str;
        for (p1=str,p2=str+strlen(str)-1;p2>p1;++p1,--p2){
            *p1^=*p2;*p2^=*p1;*p1^=*p2;
        }
    return str;
    }
#endif//system detection 

#ifdef __cplusplus
}
#endif//__cplusplus
#endif//windowsCompat_h 
