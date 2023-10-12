#ifndef multiCompat_h
#define multiCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*Shared C libraries*/
#include<stdlib.h>//system()
#include<stdio.h>//printf()

/*OS detection*/
#if defined(_WIN32) || defined(_CYGWIN_)

    #include <conio.h>  //kbhit(), getch();
    #include <windows.h>//PlaySound() need -lwinmm as compiler argument
    void Start_Compat(){SetConsoleOutputCP(CP_UTF8);}//Unicode compatibility, can be done with system("chcp 65001 > NUL"); too
    void Exit_Compat(){return;}//return to regular terminal
    void gotoxy(int x,int y){COORD coordinate;coordinate.X=x;coordinate.Y=y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);}
    int getx(){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Right-csbi.srWindow.Left);}
    int gety(){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Bottom-csbi.srWindow.Top);}

#else

    #include <ncurses.h>//getch() need -lncurses as compiler argument
    void gotoxy(int x,int y){printf("%c[%d;%df",0x1B,y,x);}
    int getx(){return getmaxx(stdscr);}
    int gety(){return getmaxy(stdscr);}
    #include <string.h>//strcat()
    void Start_Compat(){ //first function to be called inside main
        /*ncurses initialization*/
        initscr();            // Start curses mode
        raw();                // Line buffering disabled
        keypad(stdscr, TRUE); // Keyboard status
        noecho();             // Dont echo() output of getch()
        refresh();            // Update the screen to use ncurses mode
    }
    void Exit_Compat(){echo();endwin();}//End curses mode and return to regular terminal

#if defined(__linux__)

    /*Alan Cox (1995) https://www.linuxjournal.com/article/1138, Code retrivied from: https://www.linuxjournal.com/files/linuxjournal.com/linuxjournal/articles/011/1138/1138l1.html */
    #include <sys/select.h>
    int kbhit(void){struct timeval tv;fd_set read_fd;tv.tv_sec=0;tv.tv_usec=0;FD_ZERO(&read_fd);FD_SET(0,&read_fd);if(select(1, &read_fd,NULL,NULL,&tv)== -1)return 0;if(FD_ISSET(0,&read_fd))return 1;return 0;} //only works "Enter" key, insted of the "Space bar" key from Windows

#endif//LINUX
    
#endif//OS detection 

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//multiCompat_h
