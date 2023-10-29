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
    #define KEY_LEFT 75     //ascii 75 is K
    #define KEY_RIGHT 77    //ascii 77 is M
    #define KEY_UP 72       //ascii 72 is H
    #define KEY_DOWN 80     //ascii 80 is P
    #define KEY_ENTER 13   
    #define KEY_SPACE 32  
    #define KEY_TAB 9       
    #define KEY_ESC 27     
    #define KEY_BACKSPACE 8 
    #define KEY_HOME 71     //ascii 71 is G
    #define KEY_END 79      //ascii 79 is O
    #define KEY_IC 82       //ascii 82 is R
    #define KEY_DC 83       //ascii 83 is S
    #define KEY_PPAGE 73    //ascii 73 is I
    #define KEY_NPAGE 81    //ascii 81 is Q
    #define KEY_F1  59      //ascii 59 is ;
    #define KEY_F2  60      //ascii 60 is <
    #define KEY_F3  61      //ascii 61 is =
    #define KEY_F4  62      //ascii 62 is >
    #define KEY_F5  63      //ascii 63 is ?
    #define KEY_F6  64      //ascii 64 is @
    #define KEY_F7  65      //ascii 65 is A
    #define KEY_F8  66      //ascii 66 is B
    #define KEY_F9  67      //ascii 67 is C
    #define KEY_F10 68      //ascii 68 is D
    #define KEY_F11 133     
    #define KEY_F12 134     

    #include<windows.h>//GetConsoleScreenBufferInfo(),GetStdHandle(),SetConsoleCursorPosition(),COORD
    void *stdscr;//compatibility with ncurses stdscr variable
    void gotoxy(int x,int y){COORD coordinate;coordinate.X=x;coordinate.Y=y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);}
    int getmaxx(void *stdscr){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Right-csbi.srWindow.Left);}
    int getmaxy(void *stdscr){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Bottom-csbi.srWindow.Top);}
    void getmaxyx(void *stdscr,int *maxY, int *maxX){*maxY=getmaxx(stdscr); *maxX=getmaxy(stdscr);}
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
    int nocbreak_getch() {
        raw();
        int ch = getch();
        cbreak();
        return ch;
    }
    #undef getch
    #define getch() nocbreak_getch()
    #define _getch() nocbreak_getch()
    #undef  KEY_ENTER // on ncurses is ctrl + m 
    #define KEY_ENTER '\n'
    #define KEY_SPACE ' '
    #define KEY_TAB 9
    #define KEY_ESC 27
    /*You cant use parenthesis on windows*/
    #define KEY_F1  KEY_F(1)
    #define KEY_F2  KEY_F(2)
    #define KEY_F3  KEY_F(3)
    #define KEY_F4  KEY_F(4)
    #define KEY_F5  KEY_F(5)
    #define KEY_F6  KEY_F(6)
    #define KEY_F7  KEY_F(7)
    #define KEY_F8  KEY_F(8)
    #define KEY_F9  KEY_F(9)
    #define KEY_F10 KEY_F(10)
    #define KEY_F11 KEY_F(11)
    #define KEY_F12 KEY_F(12)

    
    #include <string.h>//strcat()
    void startCompat(){ //first function to be called inside main
        /*ncurses initialization*/
        initscr();            // Start curses mode
        keypad(stdscr, TRUE); // enables the use of function keys,arrow keys,etc.
        noecho();             // Dont echo() output of getch(), for a similiar functionality as conio
        cbreak();             // will break with ctrl +c like on windows
        refresh();            // Update the screen to use ncurses mode
        //raw();              // Line buffering disabled (ctrl+c disabled)
    }//startCompat()
    #define printw(args...) do{printw(args);refresh();}while(0)
    #define scanw(args...) do{echo();scanw(args);noecho();}while(0)
    void exitCompat(){refresh();echo();fflush(stdout);endwin();}//End curses mode and return to regular terminal
    void pauseCompat(){reset_shell_mode();}
    void resumeCompat(){reset_prog_mode();}


#endif//OS detection 

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//ncursesCompat_h
