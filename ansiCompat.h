#ifndef ansiCompat_h
#define ansiCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*ANSI Escape Codes Definitions*/

/*Text modifiers*/
#define BOLD          "\x1b[1m"  
#define UNDER         "\x1b[4m"  // Underline
#define UNDER_NOT     "\x1b[24m" // Not Underline
#define INREVERSE     "\x1b[7m"  
#define REVERSE       "\x1b[27m"
#define BLINK_ON      "\x1b[5m"
#define BLINK_OFF     "\x1b[25m"

    
/*Terminal modifiers*/
#define CLR_RST   "\x1b[0m"      //Reset color to default terminal color
#define BG_RST    "\x1b[49m"      //Reset color to default terminal color
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

/*Light colors (aixterm)*/
#define BLACK_LIGHT        "\x1b[90m"
#define RED_LIGHT          "\x1b[91m"       
#define GREEN_LIGHT        "\x1b[92m"      
#define YELLOW_LIGHT       "\x1b[93m"   
#define BLUE_LIGHT         "\x1b[94m"       
#define MAGENTA_LIGHT      "\x1b[95m"    
#define CYAN_LIGHT         "\x1b[96m"
#define WHITE_LIGHT        "\x1b[97m"
    
/*Dark colors*/
#define BLACK_DARK        "\x1b[1;30m"
#define RED_DARK          "\x1b[1;31m"
#define GREEN_DARK        "\x1b[1;32m"
#define YELLOW_DARK       "\x1b[1;33m"
#define BLUE_DARK         "\x1b[1;34m"
#define MAGENTA_DARK      "\x1b[1;35m"
#define CYAN_DARK         "\x1b[1;36m"
#define WHITE_DARK        "\x1b[1;37m"

/*Background Colors (ansi)*/
#define BG_BLACK        "\x1b[40m"
#define BG_RED          "\x1b[41m"
#define BG_GREEN        "\x1b[42m"
#define BG_YELLOW       "\x1b[43m"
#define BG_BLUE         "\x1b[44m"
#define BG_MAGENTA      "\x1b[45m"
#define BG_CYAN         "\x1b[46m"
#define BG_WHITE        "\x1b[47m"

/*Background Light Colors (axiterm)*/
#define BG_BLACK_LIGHT        "\x1b[100m"
#define BG_RED_LIGHT          "\x1b[101m"
#define BG_GREEN_LIGHT        "\x1b[102m"
#define BG_YELLOW_LIGHT       "\x1b[103m"
#define BG_BLUE_LIGHT         "\x1b[104m"
#define BG_MAGENTA_LIGHT      "\x1b[105m"
#define BG_CYAN_LIGHT         "\x1b[106m"
#define BG_WHITE_LIGHT        "\x1b[107m"

/*Background Dark Colors*/
#define BG_BLACK_DARK        "\x1b[1;40m"
#define BG_BLACK_DARK        "\x1b[1;40m"
#define BG_RED_DARK          "\x1b[1;41m"
#define BG_GREEN_DARK        "\x1b[1;42m"
#define BG_YELLOW_DARK       "\x1b[1;43m"
#define BG_BLUE_DARK         "\x1b[1;44m"
#define BG_MAGENTA_DARK      "\x1b[1;45m"
#define BG_CYAN_DARK         "\x1b[1;46m"
#define BG_WHITE_DARK        "\x1b[1;47m"

#include<ctype.h>
void color(char arg[2]){

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
