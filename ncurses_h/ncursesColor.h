#ifndef ncursesColorCompat_h 
#define ncursesColorCompat_h
#include <stdio.h>
#include "../ansi/ansi.h"
#include "ncurses.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(_CYGWIN_) /*OS detection | START*/

    #include <windows.h>
    #warning "atron(), atroff() implemntations needs setANSI() function to work on CMD"
    #define initscr() do{setANSI();setUTF8();}while(0)
    #define endwin()  do{clear();}while(0)

    /*Dummy functions | START*/
    void start_color(void){}
    typedef unsigned int attr_t;
    int has_colors(){return 1;}
    /*Dummy functions | END*/


    /*Colors (ncurses) | START*/
    #define COLOR_BLACK     0
    #define COLOR_RED       1
    #define COLOR_GREEN     2
    #define COLOR_YELLOW    3
    #define COLOR_BLUE      4
    #define COLOR_MAGENTA   5
    #define COLOR_CYAN      6
    #define COLOR_WHITE     7
    /*Colors (ncurses) | END*/
    
    //short max value
    #define MAX_COLOR_PAIRS 32767
    
    struct ColorPair {
        short FG;
        short BG;
    };

    //GLOBAL VARIABLES
    struct ColorPair colorPairs[MAX_COLOR_PAIRS];
    attr_t GV_nextColorPair = 1;
    attr_t GV_currentAttrs  = 0;
    short  GV_currentPair   = 0;

    void init_pair(attr_t pairNumber, attr_t foreground,attr_t background) {
        if (pairNumber > 0 && pairNumber < MAX_COLOR_PAIRS) {
            colorPairs[pairNumber].FG = foreground;
            colorPairs[pairNumber].BG = background;
        }
    }

    #define COLOR_PAIR(pairNumber) (pairNumber)

    void setConsoleColor(attr_t pairNumber){
        GV_currentPair = pairNumber;
        if(pairNumber==0){
            printf("%s", RESET_COLOR);
        }else{
            switch (colorPairs[pairNumber].FG) {
                case COLOR_BLACK:   printf("%s", FG_BLACK);   break;
                case COLOR_RED:     printf("%s", FG_RED);     break;
                case COLOR_GREEN:   printf("%s", FG_GREEN);   break;
                case COLOR_YELLOW:  printf("%s", FG_YELLOW);  break;
                case COLOR_BLUE:    printf("%s", FG_BLUE);    break;
                case COLOR_MAGENTA: printf("%s", FG_MAGENTA); break;
                case COLOR_CYAN:    printf("%s", FG_CYAN);    break;
                case COLOR_WHITE:   printf("%s", FG_WHITE);   break;
            }//ForeGround
            switch (colorPairs[pairNumber].BG) {
                case COLOR_BLACK:   printf("%s", BG_BLACK);   break;
                case COLOR_RED:     printf("%s", BG_RED);     break;
                case COLOR_GREEN:   printf("%s", BG_GREEN);   break;
                case COLOR_YELLOW:  printf("%s", BG_YELLOW);  break;
                case COLOR_BLUE:    printf("%s", BG_BLUE);    break;
                case COLOR_MAGENTA: printf("%s", BG_MAGENTA); break;
                case COLOR_CYAN:    printf("%s", BG_CYAN);    break;
                case COLOR_WHITE:   printf("%s", BG_WHITE);   break;
            }//BackGround
        }//else
    }

    #define A_BOLD      32768 //1 + MAX_COLOR_PAIRS
    #define A_DIM       32769 //2 + MAX_COLOR_PAIRS
    #define A_ITALIC    32770 //3 + MAX_COLOR_PAIRS
    #define A_UNDERLINE 32771 //4 + MAX_COLOR_PAIRS
    #define A_BLINK     32772 //5 + MAX_COLOR_PAIRS
    #define A_REVERSE   32774 //7 + MAX_COLOR_PAIRS
    #define A_STANDOUT  A_REVERSE
    #define A_INVIS     32775 //8 + MAX_COLOR_PAIRS
    #define A_COLOR 0xFFU      

    void attron(attr_t attributes){
        GV_currentAttrs = attributes;
        if (attributes<MAX_COLOR_PAIRS && attributes & A_COLOR) setConsoleColor(attributes & A_COLOR);
        else{
            if (attributes & A_BOLD)      printf("\x1b[%dm",A_BOLD      - MAX_COLOR_PAIRS);
            if (attributes & A_DIM)       printf("\x1b[%dm",A_DIM       - MAX_COLOR_PAIRS);
            if (attributes & A_ITALIC)    printf("\x1b[%dm",A_ITALIC    - MAX_COLOR_PAIRS);
            if (attributes & A_UNDERLINE) printf("\x1b[%dm",A_UNDERLINE - MAX_COLOR_PAIRS);
            if (attributes & A_BLINK)     printf("\x1b[%dm",A_BLINK     - MAX_COLOR_PAIRS);
            if (attributes & A_REVERSE)   printf("\x1b[%dm",A_REVERSE   - MAX_COLOR_PAIRS);
            if (attributes & A_STANDOUT)  printf("\x1b[%dm",A_STANDOUT  - MAX_COLOR_PAIRS);
            if (attributes & A_INVIS)     printf("\x1b[%dm",A_INVIS     - MAX_COLOR_PAIRS);
        }
    }
    void attrset(attr_t attributes){
        printf("%s", RESET_COLOR);
        attron(attributes);
    }
    void attroff(attr_t attributes){
        if (attributes<MAX_COLOR_PAIRS && attributes & A_COLOR) setConsoleColor(0);//for ncurses COLOR argument
        else{
            if (attributes & A_BOLD)      printf("\x1b[%dm",A_BOLD      + 21 - MAX_COLOR_PAIRS);
            if (attributes & A_DIM)       printf("\x1b[%dm",A_DIM       + 20 - MAX_COLOR_PAIRS);
            if (attributes & A_ITALIC)    printf("\x1b[%dm",A_ITALIC    + 20 - MAX_COLOR_PAIRS);
            if (attributes & A_UNDERLINE) printf("\x1b[%dm",A_UNDERLINE + 20 - MAX_COLOR_PAIRS);
            if (attributes & A_BLINK)     printf("\x1b[%dm",A_BLINK     + 20 - MAX_COLOR_PAIRS);
            if (attributes & A_REVERSE)   printf("\x1b[%dm",A_REVERSE   + 20 - MAX_COLOR_PAIRS);
            if (attributes & A_STANDOUT)  printf("\x1b[%dm",A_STANDOUT  + 20 - MAX_COLOR_PAIRS);
            if (attributes & A_INVIS)     printf("\x1b[%dm",A_INVIS     + 20 - MAX_COLOR_PAIRS);
        }
    }
    #define atrr_on(args)  attron(args)
    #define atrr_off(args) attroff(args)

    void getyx(void *stdscr, int *y, int *x) {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        *y = csbi.dwCursorPosition.Y;
        *x = csbi.dwCursorPosition.X;
    }
    #define getyx(stdscr, y, x) getyx(stdscr, &y, &x)

    void setConsoleBackground(attr_t attributes) {
        switch (attributes) {
            case COLOR_BLACK:   printf("%s", BG_BLACK);   break;
            case COLOR_RED:     printf("%s", BG_RED);     break;
            case COLOR_GREEN:   printf("%s", BG_GREEN);   break;
            case COLOR_YELLOW:  printf("%s", BG_YELLOW);  break;
            case COLOR_BLUE:    printf("%s", BG_BLUE);    break;
            case COLOR_MAGENTA: printf("%s", BG_MAGENTA); break;
            case COLOR_CYAN:    printf("%s", BG_CYAN);    break;
            case COLOR_WHITE:   printf("%s", BG_WHITE);   break;
        }
    }

    /*this functions may not work as expected | START*/
    int bkgdset(attr_t attributes){
        if (attributes & COLOR_BLACK)   setConsoleBackground(COLOR_BLACK);    
        if (attributes & COLOR_RED)     setConsoleBackground(COLOR_RED);
        if (attributes & COLOR_GREEN)   setConsoleBackground(COLOR_GREEN);
        if (attributes & COLOR_YELLOW)  setConsoleBackground(COLOR_YELLOW);
        if (attributes & COLOR_BLUE)    setConsoleBackground(COLOR_BLUE);
        if (attributes & COLOR_MAGENTA) setConsoleBackground(COLOR_MAGENTA); 
        if (attributes & COLOR_CYAN)    setConsoleBackground(COLOR_CYAN);
        if (attributes & COLOR_WHITE)   setConsoleBackground(COLOR_WHITE);
        else attron(attributes);
        return 0;
    }
    #define bkgd bkgdset

    int inch() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        COORD position = csbi.dwCursorPosition;
        CHAR_INFO buffer;
        SMALL_RECT rect = { position.X, position.Y, position.X, position.Y };
        ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &buffer, (COORD){1, 1}, (COORD){0, 0}, &rect);
        return buffer.Char.AsciiChar;
    }

    int attr_get(attr_t *attrs, short *pair, void *opts) {
        if (attrs == NULL || pair == NULL) return 1;
        *attrs = GV_currentAttrs;
        *pair  = GV_currentPair;
        return 0;
    }
    #define attr_get(attrs, pair, opts) attr_get(&attrs, &pair, opts);

    int mvinch(int y, int x) {
        int ch;
        attr_t attr;
        int oldY, oldX;
        getyx(stdscr, oldY, oldX);
        move(y, x);
        ch = inch();
        short pair;
        attr_get(attr,pair,NULL);
        move(oldY, oldX);
        return ch | (attr << 8);
    }

    typedef unsigned long chtype;

    #define A_CHARTEXT 0x000000ff

    void mvhline(int y, int x, chtype ch, int n) {
        for (int i = 0; i < n; i++) {
            mvaddch(y, x + i, ch);
        }
    }

    int mvvline(int y, int x, chtype ch, int n) {
        move(y, x); 
        for (int i = 0; i < n; i++) {
            move(y + i, x);
            addch(ch);
        }
        return 0;
    }
    /*this functions may not work as expected | END*/

#endif/*OS detection | END*/

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//ncursesColorCompat_h
