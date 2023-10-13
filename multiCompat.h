#ifndef multiCompat_h
#define multiCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*Shared C libraries*/
#include<stdlib.h>//system()

/*OS detection*/
#if defined(_WIN32) || defined(_CYGWIN_)
    #include<stdio.h>  //scanf(),printf()
    #include<conio.h>  //kbhit(), getch();

    /*KEYS for getch() from conio.h*/
    #define KEY_LEFT 75
    #define KEY_RIGHT 77
    #define KEY_UP 72
    #define KEY_DOWN 80
    #define KEY_ENTER 13

    #include<windows.h>//SetConsoleOutputCP(),CONSOLE_SCREEN_BUFFER_INFO,PlaySound() need -lwinmm as compiler argument
    void startCompat(){SetConsoleOutputCP(CP_UTF8);}//Unicode compatibility, can be done with system("chcp 65001 > NUL"); too
    void exitCompat(){return;}
    void pauseCompat(){return;};
    void resumeCompat(){return;};
    #define scanw(args) do{ scanf args; }while (0)
    #define printw(args) do{ printf args; }while (0)
    void gotoxy(int x,int y){COORD coordinate;coordinate.X=x;coordinate.Y=y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);}
    int getx(){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Right-csbi.srWindow.Left);}
    int gety(){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Bottom-csbi.srWindow.Top);}

#else//*NIX

    #include <ncurses.h>//getch(),scanw() need -lncurses as compiler argument
    /*ncurses.h includes stdio.h */ 
    /*for getch*/
    #define KEY_ENTER '\n' 
    void gotoxy(int x,int y){printf("%c[%d;%df",0x1B,y,x);}
    int getx(){return getmaxx(stdscr);}
    int gety(){return getmaxy(stdscr);}
    #include <string.h>//strcat()
    void startCompat(){ //first function to be called inside main
        /*ncurses initialization*/
        initscr();            // Start curses mode
        raw();                // Line buffering disabled
        keypad(stdscr, TRUE); // Keyboard status
        noecho();             // Dont echo() output of getch()
        refresh();            // Update the screen to use ncurses mode
    }//startCompat()
    void exitCompat(){echo();endwin();}//End curses mode and return to regular terminal
    void pauseCompat(){reset_shell_mode();}
    void resumeCompat(){reset_prog_mode();}
    int kbhit(){
    int ch=0, r=0; 
    nodelay(stdscr, TRUE);noecho();//turn off getch() blocking and echo
    ch = getch();// check for input
    if( ch == ERR){r = FALSE;}// no input
    else{r = TRUE;ungetch(ch);}// input
    // restore block and echo
    echo();nodelay(stdscr, FALSE);
    return(r);
    }//kbhit()  

#endif//OS detection 

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//multiCompat_h
