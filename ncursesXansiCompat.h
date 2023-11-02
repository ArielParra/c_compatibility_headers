#ifndef ncursesXansiCompat_h
#define ncursesXansiCompat_h
#include <stdio.h>
#include "ansiCompat.h"
#include "ncursesCompat.h"

#if defined(_WIN32) || defined(_CYGWIN_) /*OS detection | START*/

#include <windows.h>

#warning "atron(), atroff() implemntations needs previous call to setANSI() function to work on CMD"

#undef initscr
#undef endwin
void initscr(){setANSI();}
void endwin(){clear();}

/*Dummy functions | START*/
void start_color(void){}
#ifndef attr_t
#define attr_t unsigned int
#endif
int has_colors(){return 1;}
/*Dummy functions | END*/


/*Colors (ncurses)*/
#define COLOR_BLACK     0
#define COLOR_RED       1
#define COLOR_GREEN     2
#define COLOR_YELLOW    3
#define COLOR_BLUE      4
#define COLOR_MAGENTA   5
#define COLOR_CYAN      6
#define COLOR_WHITE     7

//type short max value is 32767
#define MAX_COLOR_PAIRS 32767

struct ColorPair {
    short FG;
    short BG;
};

// Array to store color information for different color pairs
struct ColorPair colorPairs[MAX_COLOR_PAIRS];

// GLOBAL VARIABLES
attr_t nextColorPair = 1;
attr_t currentAttrs = 0;
short currentPair = 0;

void init_pair(attr_t pairNumber, attr_t foreground,attr_t background) {
    if (pairNumber > 0 && pairNumber < MAX_COLOR_PAIRS) {
        colorPairs[pairNumber].FG = foreground;
        colorPairs[pairNumber].BG = background;
    }
}

// Macro to access color pair numbers
#define COLOR_PAIR(pairNumber) (pairNumber)

// Function to set the console text attributes based on a color pair
void setConsoleColor(attr_t pairNumber) {
    currentPair = pairNumber;
    if(pairNumber==0){
        printf("%s", RESET_COLOR);
    }else{
        switch (colorPairs[pairNumber].FG) {
            case COLOR_BLACK:   printf("%s", FG_BLACK); break;
            case COLOR_RED:     printf("%s", FG_RED); break;
            case COLOR_GREEN:   printf("%s", FG_GREEN); break;
            case COLOR_YELLOW:  printf("%s", FG_YELLOW); break;
            case COLOR_BLUE:    printf("%s", FG_BLUE); break;
            case COLOR_MAGENTA: printf("%s", FG_MAGENTA); break;
            case COLOR_CYAN:    printf("%s", FG_CYAN); break;
            case COLOR_WHITE:   printf("%s", FG_WHITE); break;
        }//ForeGround
        switch (colorPairs[pairNumber].BG) {
            case COLOR_BLACK:   printf("%s", BG_BLACK); break;
            case COLOR_RED:     printf("%s", BG_RED); break;
            case COLOR_GREEN:   printf("%s", BG_GREEN); break;
            case COLOR_YELLOW:  printf("%s", BG_YELLOW); break;
            case COLOR_BLUE:    printf("%s", BG_BLUE); break;
            case COLOR_MAGENTA: printf("%s", BG_MAGENTA); break;
            case COLOR_CYAN:    printf("%s", BG_CYAN); break;
            case COLOR_WHITE:   printf("%s", BG_WHITE); break;
        }//BackGround
    }//else
}

    #define A_BOLD      32768 //1 + MAX_COLOR_PAIRS
    #define A_DIM       32769 //2 + MAX_COLOR_PAIRS
    #define A_ITALIC    32770 //3 + MAX_COLOR_PAIRS
    #define A_UNDERLINE 32771 //4 + MAX_COLOR_PAIRS
    #define A_BLINK     32772 //5 + MAX_COLOR_PAIRS
    #define A_REVERSE   32774 //7 + MAX_COLOR_PAIRS
    #define A_INVIS     32775 //8 + MAX_COLOR_PAIRS
    #define A_STANDOUT   A_REVERSE

    void attron(attr_t attributes){
        currentAttrs = attributes;
        if (attributes & A_BOLD)      printf("\x1b[%dm",A_BOLD      - MAX_COLOR_PAIRS);
        if (attributes & A_UNDERLINE) printf("\x1b[%dm",A_UNDERLINE - MAX_COLOR_PAIRS);
        if (attributes & A_BLINK)     printf("\x1b[%dm",A_BLINK     - MAX_COLOR_PAIRS);
        if (attributes & A_ITALIC)    printf("\x1b[%dm",A_ITALIC    - MAX_COLOR_PAIRS);
        if (attributes & A_INVIS)     printf("\x1b[%dm",A_INVIS     - MAX_COLOR_PAIRS);
        if (attributes & A_REVERSE)   printf("\x1b[%dm",A_REVERSE   - MAX_COLOR_PAIRS);
        if (attributes & A_DIM)       printf("\x1b[%dm",A_DIM       - MAX_COLOR_PAIRS);
        else setConsoleColor(attributes);
    }
    void attrset(attr_t attributes){
        printf("%s", RESET_COLOR);
        attron(attributes);
    }
    void attroff(attr_t attributes){
        if (attributes & A_BOLD)      printf("\x1b[%dm",A_BOLD      + 21 - MAX_COLOR_PAIRS);
        if (attributes & A_UNDERLINE) printf("\x1b[%dm",A_UNDERLINE + 20 - MAX_COLOR_PAIRS);
        if (attributes & A_BLINK)     printf("\x1b[%dm",A_BLINK     + 20 - MAX_COLOR_PAIRS);
        if (attributes & A_ITALIC)    printf("\x1b[%dm",A_ITALIC    + 20 - MAX_COLOR_PAIRS);
        if (attributes & A_INVIS)     printf("\x1b[%dm",A_INVIS     + 20 - MAX_COLOR_PAIRS);
        if (attributes & A_REVERSE)   printf("\x1b[%dm",A_REVERSE   + 20 - MAX_COLOR_PAIRS);
        if (attributes & A_DIM)       printf("\x1b[%dm",A_DIM       + 20 - MAX_COLOR_PAIRS);
        else setConsoleColor(0);
    }

    #define atrr_on(args)  attron(args)
    #define atrr_off(args) attroff(args)

    void bkgdset(attr_t attributes){
        if (attributes & COLOR_BLACK)   printf("%s", BG_BLACK); 
        if (attributes & COLOR_RED)     printf("%s", BG_RED); 
        if (attributes & COLOR_GREEN)   printf("%s", BG_GREEN); 
        if (attributes & COLOR_YELLOW)  printf("%s", BG_YELLOW); 
        if (attributes & COLOR_BLUE)    printf("%s", BG_BLUE); 
        if (attributes & COLOR_MAGENTA) printf("%s", BG_MAGENTA);
        if (attributes & COLOR_CYAN)    printf("%s", BG_CYAN); 
        if (attributes & COLOR_WHITE)   printf("%s", BG_WHITE);
        else attron(attributes);
    }

void getyx(void *stdscr, int *y, int *x) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    *y = csbi.dwCursorPosition.Y;
    *x = csbi.dwCursorPosition.X;
}
#define getyx(stdscr, y, x) getyx(stdscr, &y, &x)

/*this fuinctions may not work as expected | START*/
int inch() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD position = csbi.dwCursorPosition;
    CHAR_INFO buffer;
    SMALL_RECT rect = { position.X, position.Y, position.X + 1, position.Y + 1 };
    ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &buffer, (COORD){1, 1}, (COORD){0, 0}, &rect);
    return buffer.Char.AsciiChar;
}
#define A_ATTRIBUTES 0xFFU // You can adjust this value as needed
#define A_COLOR 0xFFU      // You can adjust this value as needed

int attr_get(attr_t *attrs, short *pair, void *opts) {
    // Check if attrs and pair pointers are valid
    if (attrs == NULL || pair == NULL) {
        return 1;
    }

    // Set the values of attrs and pair based on the current state
    *attrs = currentAttrs;
    *pair = currentPair;

    return 0;
}
#define attr_get(attrs, pair, opts) attr_get(&attrs, &pair, opts);

int mvinch(int y, int x) {
    int ch;
    attr_t attr;

    // Save the current cursor position
    int oldY, oldX;
    getyx(stdscr, oldY, oldX);

    // Move the cursor to the specified position
    move(y, x);

    // Get the character and attributes at the specified position
    ch = inch();
    short pair;
    attr_get(attr,pair,NULL);

    // Restore the cursor position
    move(oldY, oldX);

    // Combine the character and attributes into a single integer
    return ch | (attr << 8);
}



typedef unsigned long chtype;

/* A_CHARTEXT is a bitmask to extract the character part */
#define A_CHARTEXT 0x000000ff

void mvhline(int y, int x, chtype ch, int n) {
    for (int i = 0; i < n; i++) {
        mvaddch(y, x + i, ch);
    }
}


int mvvline(int y, int x, chtype ch, int n) {
    move(y, x); // Move to the starting position (x, y)

    // Draw the vertical line using the specified character and attributes
    for (int i = 0; i < n; i++) {
        move(y + i, x); // Move to the next line
        addch(ch);
    }

    return 0; // Return OK to indicate success
}


/*this fuinctions doesnt work | END*/


#endif/*OS detection | END*/

#endif //ncursesXansiCompat_h
