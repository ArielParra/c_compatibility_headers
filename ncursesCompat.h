#ifndef ncursesCompat_h
#define ncursesCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*Shared C libraries*/
#include<stdlib.h>//system()

/*OS detection*/
#if defined(_WIN32) || defined(_CYGWIN_)
    #include<stdio.h>//scanf(),printf()
    #include<conio.h>//kbhit(),getch();

    /*KEYS for getch() from <conio.h>*/
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_ENTER 13
    #define KEY_ENTER 13
    #define KEY_BACKSPACE 8
    #define KEY_TAB 15

    #include<windows.h>//SetConsoleOutputCP(),GetConsoleScreenBufferInfo(),GetStdHandle(),SetConsoleCursorPosition(),COORD
    //For some old MinGW/CYGWIN distributions
    #ifndef CP_UTF8 
    #define CP_UTF8 65001 
    #endif
    void startCompat(){SetConsoleOutputCP(CP_UTF8);}//Unicode compatibility, can also be done with system("chcp 65001 > NUL");
    void exitCompat(void){};
    void pauseCompat(void){};
    void resumeCompat(void){};
    void refresh(void){};
    #define scanw(args...) scanf(args)
    #define printw(args...) printf(args)
    void gotoxy(int x,int y){COORD coordinate;coordinate.X=x;coordinate.Y=y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);}
    int getx(){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Right-csbi.srWindow.Left);}
    int gety(){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Bottom-csbi.srWindow.Top);}

#else//*NIX

    #include <ncurses.h>//getch(),scanw() need -lncurses as compiler argument
    /*<ncurses.h> includes <stdio.h> */ 
    /*for getch*/
    void gotoxy(int x,int y){printf("%c[%d;%df",0x1B,y,x);}
    int getx(){return getmaxx(stdscr);}
    int gety(){return getmaxy(stdscr);}
    #define _getch() getch()
    #include <string.h>//strcat()
    void startCompat(){ //first function to be called inside main
        /*ncurses initialization*/
        initscr();            // Start curses mode
        keypad(stdscr, TRUE); // enables the use of function keys,arrow keys,etc.
        noecho();             // Dont echo() output of getch(), for a similiar functionality as conio
        refresh();            // Update the screen to use ncurses mode
      //raw();                // Line buffering disabled (ctrl+c disabled)
    }//startCompat()
    #define printw(args...) do{printw(args);refresh();}while(0)
    #define scanw(args...) do{echo();scanw(args);noecho();}while(0)
    void exitCompat(){refresh();echo();endwin();}//End curses mode and return to regular terminal
    void pauseCompat(){reset_shell_mode();}
    void resumeCompat(){reset_prog_mode();}
    int kbhit(){
    int ch=0, r=0; 
        nodelay(stdscr, TRUE);
        ch = getch();
        if(ch == ERR){r = FALSE;}// no input
        else{r = TRUE;ungetch(ch);}// input
        nodelay(stdscr, FALSE);
    return(r);
    }//kbhit()  
    #define _kbhit() kbhit()

#endif//OS detection 

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//ncursesCompat_h
