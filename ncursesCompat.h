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
    #define KEY_SPACE ' '
    #define KEY_TAB 9
    #define KEY_ESC 27
    #define KEY_BACKSPACE 8
    #define KEY_HOME 71
    #define KEY_IC 82
    #define KEY_DC 83
    #define KEY_PPAGE 73
    #define KEY_NPAGE 81
    #define KEY_F(1)  59
    #define KEY_F(2)  60
    #define KEY_F(3)  61
    #define KEY_F(4)  62
    #define KEY_F(5)  63
    #define KEY_F(6)  64
    #define KEY_F(7)  65
    #define KEY_F(8)  66
    #define KEY_F(9)  67
    #define KEY_F(10) 68
    #define KEY_F(11) 133
    #define KEY_F(12) 134
    
    #include<windows.h>//GetConsoleScreenBufferInfo(),GetStdHandle(),SetConsoleCursorPosition(),COORD
    void gotoxy(int x,int y){COORD coordinate;coordinate.X=x;coordinate.Y=y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);}
    int getx(){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Right-csbi.srWindow.Left);}
    int gety(){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Bottom-csbi.srWindow.Top);}
    
    /*ncurses on Windows*/
    void startCompat(void){}
    void exitCompat(void){}
    void pauseCompat(void){}
    void resumeCompat(void){}
    
    void refresh(){fflush(stdout);}
    void initrflush(void){}
    void cbreak(void){}
    void nocbreak(void){}
    int has_colors(){return 1;}
    void start_colors(void){}
    void initsrc(){startCompat();}
    #include<stdio.h>//scanf(),printf()
    #define scanw(args...) scanf(args)
    #define printw(args...) printf(args)
    #define keypad(args...) do { } while (0)
    
    #include<string.h>//strdup(),strtok(),strcmp()
    #define atron(args) do{ \
        char *attributes = strdup(args); \
        char *token = strtok(attributes, " |"); \
        while (token != NULL) { \
            if (strcmp(token, "A_BOLD") == 0)           {printf("\x1b[1m");}\
            else if (strcmp(token, "A_UNDERLINE") == 0) {printf("\x1b[4m");}\
            else if (strcmp(token, "A_BLINK") == 0)     {printf("\x1b[5m");}\
            else if (strcmp(token, "A_ITALIC") == 0)    {printf("\x1b[3m");}\
            else if (strcmp(token, "A_INVIS") == 0)     {printf("\x1b[8m");}\
            /*else if (strcmp(token, "A_PROTECT") == 0)   {}*/\
            else if ( (strcmp(token, "A_REVERSE") == 0) ||\
            (strcmp(token, "A_SANDOUT") == 0) )         {printf("\x1b[7m");}\
            token = strtok(NULL, " |"); \
        }/*while*/\
        free(attributes); \
    }while(0)
    #define atroff(args) do{ \
        char *attributes = strdup(args); \
        char *token = strtok(attributes, " |"); \
        while (token != NULL) { \
            if (strcmp(token, "A_BOLD") == 0)           {printf("\x1b[21m");}\
            else if (strcmp(token, "A_UNDERLINE") == 0) {printf("\x1b[24m");}\
            else if (strcmp(token, "A_BLINK") == 0)     {printf("\x1b[25m");}\
            else if (strcmp(token, "A_ITALIC") == 0)    {printf("\x1b[23m");}\
            else if (strcmp(token, "A_INVIS") == 0)     {printf("\x1b[28m");}\
            /*else if (strcmp(token, "A_PROTECT") == 0)   {}*/\
            else if ( (strcmp(token, "A_REVERSE") == 0) ||\
            (strcmp(token, "A_SANDOUT") == 0) )         {printf("\x1b[27m");}\
            token = strtok(NULL, " |"); \
        }/*while*/\
        free(attributes); \
    }while(0)
    #define mvprintw(row, col, format, ...) do { \
        gotoxy(x+1,y+1);\
        printf(format, __VA_ARGS__); \
    } while (0)    
    #define atrr_on(args) atron(args)
    #define atrr_off(args) atroff(args)


#else//*NIX
    
    #include <ncurses.h>//getch(),scanw() need -lncurses as compiler argument
    /*<ncurses.h> includes <stdio.h> */ 
    void gotoxy(int x,int y){printf("%c[%d;%df",0x1B,y,x);}
    int getx(){return getmaxx(stdscr);}
    int gety(){return getmaxy(stdscr);}
    #define _getch() getch()
    
    #undef  KEY_ENTER // on ncurses is ctrl + m 
    #define KEY_ENTER '\n'
    #define KEY_SPACE ' '
    #define KEY_TAB 9
    #define KEY_ESC 27
    
    #include <string.h>//strcat()
    void startCompat(){ //first function to be called inside main
        /*ncurses initialization*/
        initscr();            // Start curses mode
        keypad(stdscr, TRUE); // enables the use of function keys,arrow keys,etc.
        noecho();             // Dont echo() output of getch(), for a similiar functionality as conio
        cbreak();             // will break with ctrl +c like on windows
        refresh();            // Update the screen to use ncurses mode
      //raw();                // Line buffering disabled (ctrl+c disabled)
    }//startCompat()
    #define printw(args...) do{printw(args);refresh();}while(0)
    #define scanw(args...) do{echo();scanw(args);noecho();}while(0)
    void exitCompat(){refresh();echo();fflush(stdout);endwin();}//End curses mode and return to regular terminal
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
