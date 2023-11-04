#ifndef conioCompat_h
#define conioCompat_h
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/*<conio.h> Turbo C color macros | START*/
#define BLACK        0
#define BLUE         1
#define GREEN        2
#define CYAN         3
#define RED          4
#define MAGENTA      5
#define BROWN        6
#define LIGHTGRAY    7
#define DARKGRAY     8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTCYAN    11
#define LIGHTRED     12
#define LIGHTMAGENTA 13
#define YELLOW       14
#define WHITE        15
/*<conio.h> Turbo C color macros | END*/

#if defined(_WIN32) || defined(_CYGWIN_) /*OS detection | START*/
    #include<stdio.h>//scanf(),printf()
    #include<windows.h>//GetConsoleScreenBufferInfo(),GetStdHandle(),SetConsoleCursorPosition(),COORD
    #include<conio.h>//kbhit(),getch();

    /*Old turbo C <conio.h> functions | START*/
    #include <stdio.h>
    void clrscr(){system("cls");}; 
    void gotoxy(int x,int y){COORD coordinate;coordinate.X=x;coordinate.Y=y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);}
    void textbackground(int color) {//Not working as expected
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int attr = 0;
        switch (color) {
            case BLACK:     attr = 0;break;
            case BLUE:      attr = BACKGROUND_BLUE;break;
            case GREEN:     attr = BACKGROUND_GREEN;break;
            case CYAN:      attr = BACKGROUND_GREEN | BACKGROUND_BLUE;break;
            case RED:       attr = BACKGROUND_RED;break;
            case MAGENTA:   attr = BACKGROUND_RED | BACKGROUND_BLUE;break;
            case BROWN:     attr = BACKGROUND_RED | BACKGROUND_GREEN;break;
            case LIGHTGRAY: attr = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;break;
            default:attr = 0; // Default to black background
        }
        SetConsoleTextAttribute(hConsole, attr);
    }
    void textcolor(int color) {//Not working as expected
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int attr = 0;
        switch (color) {
            case BLACK:     attr = 0;break;
            case BLUE:      attr = FOREGROUND_BLUE;break;
            case GREEN:     attr = FOREGROUND_GREEN;break;
            case CYAN:      attr = FOREGROUND_GREEN | FOREGROUND_BLUE;break;
            case RED:       attr = FOREGROUND_RED;break;
            case MAGENTA:   attr = FOREGROUND_RED | FOREGROUND_BLUE;break;
            case BROWN:     attr = FOREGROUND_RED | FOREGROUND_GREEN;break;
            case LIGHTGRAY: attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;break;
            default:attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; // Default to white
        }   
        SetConsoleTextAttribute(hConsole, attr);
    }
    void delay(int ms){Sleep(ms);} 
    #define cputs _cputs
    /*Old turbo C <conio.h> functions | END*/

    /*My Functions | START*/
    void startCompat(){}
    void exitCompat(){}
    /*My Functions | START*/


#else//*NIX

    /*Old turbo C <conio.h> functions | START*/
   void gotoxy(int x,int y){move(y, x);}
    int kbhit(){
    int ch=0, r=0; 
        nodelay(stdscr, TRUE);
        ch = getch();
        if(ch == ERR){r = FALSE;}  // no input
        else{r = TRUE;ungetch(ch);}// input
        nodelay(stdscr, FALSE);
    return(r);
    }//kbhit()  
    #define _kbhit() kbhit()
    
    #include<unistd.h>//usleep()
    void delay(unsigned int ms){usleep(ms*1000);} 

    void textbackground(int color) {//Not tested
        int bg_color = COLOR_BLACK;  
        switch(){
            case BLACK:         bg_color = COLOR_BLACK;break
            case BLUE:          bg_color = COLOR_CYAN;break
            case GREEN:         bg_color = COLOR_GREEN;break
            case CYAN:          bg_color = COLOR_BLUE;break
            case RED:           bg_color = COLOR_RED;break
            case MAGENTA:       bg_color = COLOR_MAGENTA;break
            case BROWN:         bg_color = COLOR_YELLOW;break
            case LIGHTGRAY:     bg_color = COLOR_WHITE;break
            case DARKGRAY:      bg_color = COLOR_BLACK;break
            case LIGHTBLUE:     bg_color = COLOR_CYAN;break
            case LIGHTGREEN:    bg_color = COLOR_GREEN;break
            case LIGHTCYAN:     bg_color = COLOR_BLUE;break
            case LIGHTRED:      bg_color = COLOR_RED;break
            case LIGHTMAGENTA:  bg_color = COLOR_MAGENTA;break
            case YELLOW:        bg_color = COLOR_YELLOW;break;
            case WHITE:         bg_color = COLOR_WHITE;break;    
        }
        bkgd(COLOR_PAIR(bg_color)); refresh();
    }
    void textcolor(int color) {//Not tested
        int fg_color = COLOR_WHITE;  
        switch(){
            case BLACK:         fg_color = COLOR_BLACK;break
            case BLUE:          fg_color = COLOR_CYAN;break
            case GREEN:         fg_color = COLOR_GREEN;break
            case CYAN:          fg_color = COLOR_BLUE;break
            case RED:           fg_color = COLOR_RED;break
            case MAGENTA:       fg_color = COLOR_MAGENTA;break
            case BROWN:         fg_color = COLOR_YELLOW;break
            case LIGHTGRAY:     fg_color = COLOR_WHITE;break
            case DARKGRAY:      fg_color = COLOR_BLACK;break
            case LIGHTBLUE:     fg_color = COLOR_CYAN;break
            case LIGHTGREEN:    fg_color = COLOR_GREEN;break
            case LIGHTCYAN:     fg_color = COLOR_BLUE;break
            case LIGHTRED:      fg_color = COLOR_RED;break
            case LIGHTMAGENTA:  fg_color = COLOR_MAGENTA;break
            case YELLOW:        fg_color = COLOR_YELLOW;break;
            case WHITE:         fg_color = COLOR_WHITE;break;
        }
        attron(COLOR_PAIR(fg_color));refresh();
    }

    /*Old turbo C <conio.h> functions | END*/


    /*conio.h Compatibility | START*/
    
    /*<ncurses.h> includes <stdio.h> */ 
    #include <ncurses.h>//getch(),scanw(),
    #warning "ncurses.h needs -lncurses as a compiler argument"

    #include <string.h>//strcat()
    void startCompat(){ //first function to be called inside main
        /*ncurses initialization*/
        initscr();            // Start curses mode
        keypad(stdscr, TRUE); // enables the use of function keys,arrow keys,etc.
        noecho();             // Dont echo() output of getch(), for a similiar functionality as conio
        cbreak();             // will break with ctrl +c like on Windows
        refresh();            // Update the screen to use ncurses mode
    }//startCompat()
    void exitCompat(){refresh();echo();fflush(stdout);endwin();}

    #define printw(args...) do{printw(args);refresh();}while(0)     // to work similar to printf
    #define scanw(args...) do{echo();scanw(args);noecho();}while(0) // to work similar to scanf

    int nocbreak_getch() {
        raw();
        int ch = getch();
        cbreak();
        return ch;
    }
    #undef  getch
    #define getch() nocbreak_getch()
    #define _getch() nocbreak_getch()
    

    #define printw(args...) do{printw(args);refresh();}while(0)         // to work similar to printf
    #define scanw(args...) do{echo();scanw(args);noecho();}while(0)     // to work similar to scanf
    #define cprintf(format, ...)do { printf(format, __VA_ARGS__); } while (0)
    #define _cprintf cprintf
    /*conio.h Compatibility | END*/


#endif/*OS detection | END*/


#ifdef __cplusplus
}
#endif//__cplusplus

#endif//conioCompat_h