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
#define BLACK_DARK        "\x1b[100m"
#define RED_DARK          "\x1b[101m"       
#define GREEN_DARK        "\x1b[102m"      
#define YELLOW_DARK       "\x1b[103m"   
#define BLUE_DARK         "\x1b[104m"       
#define MAGENTA_DARK      "\x1b[105m"    
#define CYAN_DARK         "\x1b[106m"
#define WHITE_DARK        "\x1b[107m"

/*Background Colors*/
#define BG_BLACK        "\x1b[40m"
#define BG_RED          "\x1b[41m"
#define BG_GREEN        "\x1b[42m"
#define BG_YELLOW       "\x1b[43m"
#define BG_BLUE         "\x1b[44m"
#define BG_MAGENTA      "\x1b[45m"
#define BG_CYAN         "\x1b[46m"
#define BG_WHITE        "\x1b[47m"

/*Background Light Colors*/
#define BG_BLACK_LIGHT        "\x1b[2;40m"
#define BG_BLACK_LIGHT        "\x1b[2;40m"
#define BG_RED_LIGHT          "\x1b[2;41m"
#define BG_GREEN_LIGHT        "\x1b[2;42m"
#define BG_YELLOW_LIGHT       "\x1b[2;43m"
#define BG_BLUE_LIGHT         "\x1b[2;44m"
#define BG_MAGENTA_LIGHT      "\x1b[2;45m"
#define BG_CYAN_LIGHT         "\x1b[2;46m"
#define BG_WHITE_LIGHT        "\x1b[2;47m"

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

#if defined(_WIN32) || defined(_CYGWIN_)
    /*KEYS for getch() from conio.h*/
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_ENTER 13
#else //for all *NIX 
    #define KEY_ENTER '\n' 
#endif//Windows OS detection

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//ansiCompat_h
