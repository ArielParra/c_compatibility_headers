#include <windows.h>
#include <stdio.h>
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
#define FG_BLACK            "\x1b[30m"
#define FG_RED              "\x1b[31m"       
#define FG_GREEN            "\x1b[32m"      
#define FG_YELLOW           "\x1b[33m"   
#define FG_BLUE             "\x1b[34m"       
#define FG_MAGENTA          "\x1b[35m"    
#define FG_CYAN             "\x1b[36m"
#define FG_WHITE            "\x1b[37m"
#define FG_DEFAULT          "\x1b[39m" 

    #define COLOR_BLACK     0
    #define COLOR_RED       1
    #define COLOR_GREEN     2
    #define COLOR_YELLOW    3
    #define COLOR_BLUE      4
    #define COLOR_MAGENTA   5
    #define COLOR_CYAN      6
    #define COLOR_WHITE     7

//short int max is 32767
#define MAX_COLOR_PAIRS 32767

// Struct to hold color information
struct ColorPair {
    int FG;
    int BG;
};

// Array to store color information for different color pairs
struct ColorPair colorPairs[MAX_COLOR_PAIRS];

/*
//NEEDS color pair 0 being default terminal colors

//falta implementar
color_set();
attr_set();
*/


// Counter for the next available color pair
int nextColorPair = 1;

// Function to initialize color pairs
void init_pair(int pairNumber, int foreground, int background) {
    if (pairNumber > 0 && pairNumber < MAX_COLOR_PAIRS) {
        colorPairs[pairNumber].FG = foreground;
        colorPairs[pairNumber].BG = background;
    }
}

// Macro to access color pair numbers
#define COLOR_PAIR(pairNumber) (pairNumber)

// Function to set the console text attributes based on a color pair
void setConsoleColor(int pairNumber) {
    switch (colorPairs[pairNumber].FG) {
        case COLOR_BLACK: printf("%s", FG_BLACK); break;
        case COLOR_RED:   printf("%s", FG_RED); break;
        case COLOR_GREEN: printf("%s", FG_GREEN); break;
        case COLOR_YELLOW: printf("%s", FG_YELLOW); break;
        case COLOR_BLUE:  printf("%s", FG_BLUE); break;
        case COLOR_MAGENTA: printf("%s", FG_MAGENTA); break;
        case COLOR_CYAN: printf("%s", FG_CYAN); break;
        case COLOR_WHITE: printf("%s", FG_WHITE); break;
    }//ForeGround
    switch (colorPairs[pairNumber].BG) {
        case COLOR_BLACK: printf("%s", BG_BLACK); break;
        case COLOR_RED:   printf("%s", BG_RED); break;
        case COLOR_GREEN: printf("%s", BG_GREEN); break;
        case COLOR_YELLOW: printf("%s", BG_YELLOW); break;
        case COLOR_BLUE:  printf("%s", BG_BLUE); break;
        case COLOR_MAGENTA: printf("%s", BG_MAGENTA); break;
        case COLOR_CYAN: printf("%s", BG_CYAN); break;
        case COLOR_WHITE: printf("%s", BG_WHITE); break;
    }//BackGround
}

    #define A_BOLD      1
    #define A_UNDERLINE 4
    #define A_BLINK     5
    #define A_ITALIC    3
    #define A_INVIS     8
    #define A_REVERSE   7
    #define A_SANDOUT   A_REVERSE
void attron(unsigned int attributes){
        if (attributes & A_BOLD)      printf("\x1b[%dm",A_BOLD);
        if (attributes & A_UNDERLINE) printf("\x1b[%dm",A_UNDERLINE);
        if (attributes & A_BLINK)     printf("\x1b[%dm",A_BLINK);
        if (attributes & A_ITALIC)    printf("\x1b[%dm",A_ITALIC);
        if (attributes & A_INVIS)     printf("\x1b[%dm",A_INVIS);
        if (attributes & A_REVERSE)   printf("\x1b[%dm",A_REVERSE);
    }
    void attroff(unsigned int attributes){
        if (attributes & A_BOLD)      printf("\x1b[%dm",A_BOLD+21);
        if (attributes & A_UNDERLINE) printf("\x1b[%dm",A_UNDERLINE+20);
        if (attributes & A_BLINK)     printf("\x1b[%dm",A_BLINK+20);
        if (attributes & A_ITALIC)    printf("\x1b[%dm",A_ITALIC+20);
        if (attributes & A_INVIS)     printf("\x1b[%dm",A_INVIS+20);
        if (attributes & A_REVERSE)     printf("\x1b[%dm",A_REVERSE+20);
    }

int main() {
    // Initialize the console
    setANSI();  


    // Initialize color pair 1 (Red on Black)
    init_pair(1, COLOR_BLACK, COLOR_RED);    // Color pair 1: Red text on black background


    // Set and use color pair 1 (Red on Black)
    setConsoleColor(COLOR_PAIR(1));
    printf("This text is red on a black background.\n");

    // Restore the original text attributes

    return 0;
}
