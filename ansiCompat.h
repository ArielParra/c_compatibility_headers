#ifndef ansiCompat_h
#define ansiCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*ANSI Escape Codes Definitions*/

/*Text modifiers*/
#define BOLD_ON       "\x1b[1m"  
#define BOLD_OFF      "\x1b[21m"  
#define UNDER_ON      "\x1b[4m"  // Underline
#define UNDER_OFF     "\x1b[24m" // Not Underline
#define REVERSE_ON    "\x1b[7m"  
#define REVERSE_OFF   "\x1b[27m"
#define BLINK_ON      "\x1b[5m"
#define BLINK_OFF     "\x1b[25m"

    
/*Terminal modifiers*/
#define CLR_RST   "\x1b[0m"      //Reset color to default terminal color
#define HIDE_CRSR "\033[?25l"    //Hide Terminal Cursor
#define SHOW_CRSR "\033[?25h"    //Show Terminal Cursor
#define CLR_SCRN  "\e[1;1H\e[2J" //Clear Screen 

/*colors*/
#define BLACK        "\x1b[30m"
#define RED          "\x1b[31m"       
#define GREEN        "\x1b[32m"      
#define YELLOW       "\x1b[33m"   
#define BLUE         "\x1b[34m"       
#define MAGENTA      "\x1b[35m"    
#define CYAN         "\x1b[36m"
#define WHITE        "\x1b[37m"
#define DEFAULT      "\x1b[39m" 

/*Light colors (aixterm)*/
#define BLACK_LIGHT        "\x1b[90m"
#define RED_LIGHT          "\x1b[91m"       
#define GREEN_LIGHT        "\x1b[92m"      
#define YELLOW_LIGHT       "\x1b[93m"   
#define BLUE_LIGHT         "\x1b[94m"       
#define MAGENTA_LIGHT      "\x1b[95m"    
#define CYAN_LIGHT         "\x1b[96m"
#define WHITE_LIGHT        "\x1b[97m"
    
/*Background Colors (ansi)*/
#define BG_BLACK        "\x1b[40m"
#define BG_RED          "\x1b[41m"
#define BG_GREEN        "\x1b[42m"
#define BG_YELLOW       "\x1b[43m"
#define BG_BLUE         "\x1b[44m"
#define BG_MAGENTA      "\x1b[45m"
#define BG_CYAN         "\x1b[46m"
#define BG_WHITE        "\x1b[47m"
#define BG_DEFAULT      "\x1b[49m" 

/*Background Light Colors (axiterm)*/
#define BG_BLACK_LIGHT        "\x1b[100m"
#define BG_RED_LIGHT          "\x1b[101m"
#define BG_GREEN_LIGHT        "\x1b[102m"
#define BG_YELLOW_LIGHT       "\x1b[103m"
#define BG_BLUE_LIGHT         "\x1b[104m"
#define BG_MAGENTA_LIGHT      "\x1b[105m"
#define BG_CYAN_LIGHT         "\x1b[106m"
#define BG_WHITE_LIGHT        "\x1b[107m"

#include<ctype.h>
#include<stdio.h>
void color(char arg[3]){

printf(CLR_RST); //by default
    
    /*ForeGround (text color)*/
    if (isdigit(arg[0]) || isalpha(arg[0])){
            switch (arg[0]) { 
                case '0': printf(BLACK); break; 
                case '1': printf(BLUE); break; 
                case '2': printf(GREEN); break; 
                case '3': printf(CYAN); break;        //Windows aqua
                case '4': printf(RED); break; 
                case '5': printf(MAGENTA); break;     //Windows purple
                case '6': printf(YELLOW); break; 
                case '7': printf(WHITE); break; 
                case '8': printf(BLACK_LIGHT); break; //Windows purple
                case '9': printf(BLUE_LIGHT); break; 
                case 'a': case 'A': printf(GREEN_LIGHT); break; 
                case 'b': case 'B': printf(CYAN_LIGHT); break; 
                case 'c': case 'C': printf(RED_LIGHT); break; 
                case 'd': case 'D': printf(MAGENTA_LIGHT); break; 
                case 'e': case 'E': printf(YELLOW_LIGHT); break; 
                case 'f': case 'F': printf(WHITE_LIGHT); break; 
                default: printf(CLR_RST); //for unknown argument 
            } 
    }
    /*BackGround*/
    if(arg[1]!='\0' && (isdigit(arg[1]) || isalpha(arg[1])) ){
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
                default: printf(CLR_RST); //for unknown argument
            }//switch 
    }//if
}//color()

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//ansiCompat_h
