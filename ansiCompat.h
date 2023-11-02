#ifndef ansiCompat_h
#define ansiCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*ANSI Escape Codes Definitions*/

/*Text modifiers*/
#define RESET_TEXT       "\x1b[0m"
#define BOLD_ON          "\x1b[1m"
#define BOLD_OFF         "\x1b[22m"
#define UNDERLINE_ON     "\x1b[4m"
#define UNDERLINE_ON     "\x1b[4m"
#define UNDERLINE_OFF    "\x1b[24m"
#define REVERSE_ON       "\x1b[7m"
#define REVERSE_OFF      "\x1b[27m"
#define INVISIBLE_ON     "\x1b[8m"
#define INVISIBLE_OFF    "\x1b[28m"
/*Usually not supported */
#define DIM_ON           "\x1b[2m"
#define DIM_OFF          "\x1b[22m"
#define CROSS_ON         "\x1b[9m"
#define CROSS_OFF        "\x1b[29m"
#define BLINK_ON         "\x1b[5m"
#define BLINK_OFF        "\x1b[25m"
#define ITALIC_ON        "\x1b[3m"
#define ITALIC_OFF       "\x1b[23m"

/*Terminal modifiers*/
#define RESET_COLOR      "\x1b[0m"      //Reset color to default terminal color
#define CURSOR_OFF       "\033[?25h"    //Hide Terminal Cursor
#define CURSOR_ON        "\033[?25l"    //Show Terminal Cursor
#define CLEAR_SCREEN     "\e[1;1H\e[2J" //Clear Screen 

/*Foreground colors (ansi)*/
#define FG_BLACK            "\x1b[30m"
#define FG_RED              "\x1b[31m"       
#define FG_GREEN            "\x1b[32m"      
#define FG_YELLOW           "\x1b[33m"   
#define FG_BLUE             "\x1b[34m"       
#define FG_MAGENTA          "\x1b[35m"    
#define FG_CYAN             "\x1b[36m"
#define FG_WHITE            "\x1b[37m"
#define FG_DEFAULT          "\x1b[39m" 


/*Light colors (aixterm)*/
#define FG_BLACK_LIGHT      "\x1b[90m"
#define FG_RED_LIGHT        "\x1b[91m"       
#define FG_GREEN_LIGHT      "\x1b[92m"      
#define FG_YELLOW_LIGHT     "\x1b[93m"   
#define FG_BLUE_LIGHT       "\x1b[94m"       
#define FG_MAGENTA_LIGHT    "\x1b[95m"    
#define FG_CYAN_LIGHT       "\x1b[96m"
#define FG_WHITE_LIGHT      "\x1b[97m"
    
/*Background Colors (ansi)*/
#define BG_BLACK            "\x1b[40m"
#define BG_RED              "\x1b[41m"
#define BG_GREEN            "\x1b[42m"
#define BG_YELLOW           "\x1b[43m"
#define BG_BLUE             "\x1b[44m"
#define BG_MAGENTA          "\x1b[45m"
#define BG_CYAN             "\x1b[46m"
#define BG_WHITE            "\x1b[47m"
#define BG_DEFAULT          "\x1b[49m" 

/*Background Light Colors (axiterm)*/
#define BG_BLACK_LIGHT      "\x1b[100m"
#define BG_RED_LIGHT        "\x1b[101m"
#define BG_GREEN_LIGHT      "\x1b[102m"
#define BG_YELLOW_LIGHT     "\x1b[103m"
#define BG_BLUE_LIGHT       "\x1b[104m"
#define BG_MAGENTA_LIGHT    "\x1b[105m"
#define BG_CYAN_LIGHT       "\x1b[106m"
#define BG_WHITE_LIGHT      "\x1b[107m"


/*Windows ANSI compatibility by setting output mode to handle virtual terminal sequences*/
#if defined(_WIN32) || defined(__CYGWIN__)

#include <windows.h>//DWORD,GetConsoleMode(),GetStdHandle(),SetConsoleOutputCP()

//For some old MinGW/CYGWIN distributions
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING 
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#ifndef CP_UTF8 
#define CP_UTF8 65001 
#endif

void setANSI(){//sets virtual terminal
    DWORD console_mode;
    GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &console_mode);
    console_mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), console_mode);
}
void setUTF8(){SetConsoleOutputCP(CP_UTF8);}//Unicode compatibility, can also be done with system("chcp 65001 > NUL");

#else//*NIX
void setANSI(void){}
void setUTF8(void){}//not needed in most *NIX systems
//void setUTF8(){system("export LANG=en_US.UTF-8");}
//void setUTF8(){setlocale(LC_ALL, "en_US.UTF-8");}//with <ncurses.h> needs -lncurses as compiler argument
#endif//windows detection

#include<stdio.h>//printf()

void setTitle(const char *str){printf("\033]0;%s\007",str);}

void ansiGotoxy(int x,int y){printf("%c[%d;%df",0x1B,y,x);}

void color(const char *arg){

    printf(RESET_COLOR); //by default

    /*ForeGround (text color)*/
    //if( isdigit(arg[0]) || isalpha(arg[0]) ){ // uses <ctype.h>
    if( ( arg[0] >= '0' && arg[0] <= '9') || ( (arg[0] >= 'a' && arg[0] <= 'z') || (arg[0] >= 'A' && arg[0] <= 'Z') ) ){
        switch (arg[0]) { 
            case '0': printf(FG_BLACK); break; 
            case '1': printf(FG_BLUE); break; 
            case '2': printf(FG_GREEN); break; 
            case '3': printf(FG_CYAN); break;        //Windows aqua
            case '4': printf(FG_RED); break; 
            case '5': printf(FG_MAGENTA); break;     //Windows purple
            case '6': printf(FG_YELLOW); break; 
            case '7': printf(FG_WHITE); break; 
            case '8': printf(FG_BLACK_LIGHT); break; //Windows purple
            case '9': printf(FG_BLUE_LIGHT); break; 
            case 'a': case 'A': printf(FG_GREEN_LIGHT); break; 
            case 'b': case 'B': printf(FG_CYAN_LIGHT); break; 
            case 'c': case 'C': printf(FG_RED_LIGHT); break; 
            case 'd': case 'D': printf(FG_MAGENTA_LIGHT); break; 
            case 'e': case 'E': printf(FG_YELLOW_LIGHT); break; 
            case 'f': case 'F': printf(FG_WHITE_LIGHT); break; 
            default: printf(RESET_COLOR); //for unknown argument 
        }//siwtch
    }//if

    /*BackGround*/
    //if(arg[1]!='\0' && arg[2] == '\0' && ( isdigit(arg[1]) || isalpha(arg[1]) ) ){ // uses <ctype.h> 
    if(arg[1] != '\0' && arg[2] == '\0' && ( (arg[1] >= '0' && arg[1] <= '9') || ( (arg[1] >= 'a' && arg[1] <= 'z') || (arg[1] >= 'A' && arg[1] <= 'Z') ) ) ) {
        switch (arg[1]) { 
            case '0': printf(BG_BLACK); break; 
            case '1': printf(BG_BLUE); break; 
            case '2': printf(BG_GREEN); break; 
            case '3': printf(BG_CYAN); break;        //Windows aqua
            case '4': printf(BG_RED); break; 
            case '5': printf(BG_MAGENTA); break;     //Windows purple
            case '6': printf(BG_YELLOW); break; 
            case '7': printf(BG_WHITE); break; 
            case '8': printf(BG_BLACK_LIGHT); break; //Windows gray
            case '9': printf(BG_BLUE_LIGHT); break; 
            case 'a': case 'A': printf(BG_GREEN_LIGHT); break; 
            case 'b': case 'B': printf(BG_CYAN_LIGHT); break; 
            case 'c': case 'C': printf(BG_RED_LIGHT); break; 
            case 'd': case 'D': printf(BG_MAGENTA_LIGHT); break; 
            case 'e': case 'E': printf(BG_YELLOW_LIGHT); break; 
            case 'f': case 'F': printf(BG_WHITE_LIGHT); break; 
            default: printf(RESET_COLOR); //for unknown argument
        }//switch 
    }//if
}//color()

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//ansiCompat_h
