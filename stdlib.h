#ifndef stdlibCompat_h 
#define stdlibCompat_h 

#ifndef __GNUC__
    #warning "You are not using Gnu C Compiler (GCC)"
#endif

#ifdef __clang__
    #warning "Clang compiler is being used"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*Shared C libraries | START*/
#include<stdlib.h>//system() //Windows: itoa(), ltoa(), _ultoa()
/*Shared C libraries | END*/

#if defined(_WIN32) || defined(__CYGWIN__)/*OS detection | START*/

    #define ultoa(args...) _ultoa(args)
    void sysClear(){ system("cls"); } 
    void sysPause(){ system("pause"); }

#else//*NIX

    #include <stdio.h> //sprintf()
    #include <string.h>//strcmp(), strcpy()

    void sysClear(){system("clear");}
    //void sysPause(){system("read -r -n 1 -p 'Presiona cualquier tecla para contiuar . . .'");}//Español
    void sysPause(){system("read -r -n 1 -p 'Press any key to continue . . .'");}//English

    /*Redefinition of Windows system("pause") to sysPause() or system("cls" to sysclear)*/
    #define system(cmd) do{ \
        if(strcmp(cmd,"pause")==0 || strcmp(cmd,"PAUSE") ==0){ sysPause(); } \
        else if(strcmp(cmd,"cls")==0 || strcmp(cmd,"CLS")==0){ sysClear(); } \
        else{system(cmd);}\
    }while(0)
    
    #define TO_ASCII(num, str, base) do{ \
        if(base<2) exit(1); \
        size_t i=0; \
        if(num==0){ str[i++]='0';str[i]='\0';return str; } \
        int isNegative=0; \
        if (num<0){ isNegative=1;num=-num; } \
        while(num!=0){ \
            str[i++]=(num%base> 9) ? (num%base - 10) + 'a' : num%base + '0'; \
            num/=base; \
        }\
        if (isNegative==1 && base==10) str[i++] = '-'; \
        str[i] = '\0'; \
        /*strrev function:*/ \
        char *p1,*p2; \
        if (! str || ! *str) return str; \
        for (p1=str,p2=str+strlen(str)-1;p2>p1;++p1,--p2){ \
            *p1^=*p2;*p2^=*p1;*p1^=*p2; \
        } \
    return str;\
    } while (0)
    char* ltoa(long num,char* str,int base){          TO_ASCII(num, str, base);}
    char* ultoa(unsigned long num,char* str,int base){TO_ASCII(num, str, base);}
    char* itoa(int num,char* str,int base){           TO_ASCII(num, str, base);}
    #define _ltoa(args...) ltoa(args)
    #define _ultoa(args...) ultoa(args)
    #define _itoa(args...) itoa(args)
    #define _sleep(args) Sleep(args)

#endif/*OS detection | END*/

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//stdlibCompat_h 
