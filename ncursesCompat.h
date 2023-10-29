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
    #define KEY_ENTER 13    //'\n' on ncurses
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

    /*My Functions*/
    void startCompat(void){}
    void exitCompat(void){}
    void pauseCompat(void){}
    void resumeCompat(void){}

    /*ncurses compatibility for Windows*/
    
    /*Dummy functions*/
    void initrflush(void){}
    void echo(void){}
    void noecho(void){}
    void cbreak(void){}
    void nocbreak(void){}
    void raw(void){}
    void start_color(void){} 
    void *stdscr=NULL;

    /*ncurses functions*/
    void gotoxy(int x,int y){COORD coordinate;coordinate.X=x;coordinate.Y=y; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);}
    int getmaxx(void *stdscr){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Right-csbi.srWindow.Left);}
    int getmaxy(void *stdscr){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Bottom-csbi.srWindow.Top);}
    void getmaxyx(void *stdscr, int *y, int *x) {*y=getmaxy(stdscr);*x=getmaxx(stdscr);}
    #define getmaxyx(stdscr, maxY, maxX) getmaxyx(stdscr, &maxY, &maxX) //force the use of pointers
    #define move(x,y) gotoxy(x,y)
    void addch(char ch) {printf("%c", ch);}
    void addstr(const char* str) { while (*str) { addch(*str); str++;} }
    void mvaddch(int y, int x, char ch) {gotoxy(x, y);addch(ch);}
    int mvgetch(int y, int x) {gotoxy(x, y);return getch();}
    void getstr(char* str) {scanf("%s", str);}
    void mvgetstr(int y, int x, char* str) {gotoxy(x, y);getstr(str);}
    int has_colors(){return 1;}
    void refresh(){fflush(stdout);}
    void initscr(){startCompat();}
    void endwin(){exitCompat();}
    void keypad(void *stdscr,int bool){}
    void clrtobot() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;COORD cursorPos;DWORD count;DWORD cellCount;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        cellCount = (csbi.dwSize.X - csbi.dwCursorPosition.X) + (csbi.dwSize.X * (csbi.dwSize.Y - csbi.dwCursorPosition.Y - 1));
        cursorPos.X = csbi.dwCursorPosition.X;cursorPos.Y = csbi.dwCursorPosition.Y;
        FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', cellCount, cursorPos, &count);
        FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes, cellCount, cursorPos, &count);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwCursorPosition);
    }

    void clear() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);COORD topLeft = {0, 0};
        DWORD written;CONSOLE_SCREEN_BUFFER_INFO csbi;DWORD cellsToClear;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        cellsToClear = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputCharacter(hConsole, ' ', cellsToClear, topLeft, &written);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellsToClear, topLeft, &written);
        SetConsoleCursorPosition(hConsole, topLeft);
    }

    #define scanw(args...) scanf(args)
    #define printw(args...) printf(args)
    #define mvprintw(x, y, format, ...) do { \
        gotoxy(x,y);\
        printf(format, __VA_ARGS__); \
    } while (0)
/*
//atron atroff ncurses functions
    #include<string.h>//strdup(),strtok(),strcmp()
    #define attron(args) do{ \
        char *attributes = strdup(args); \
        char *token = strtok(attributes, " |"); \
        while (token != NULL) { \
            if (strcmp(token, "A_BOLD") == 0)           {printf("\x1b[1m");}\
            else if (strcmp(token, "A_UNDERLINE") == 0) {printf("\x1b[4m");}\
            else if (strcmp(token, "A_BLINK") == 0)     {printf("\x1b[5m");}\
            else if (strcmp(token, "A_ITALIC") == 0)    {printf("\x1b[3m");}\
            else if (strcmp(token, "A_INVIS") == 0)     {printf("\x1b[8m");}\
            else if ( (strcmp(token, "A_REVERSE") == 0) ||\
            (strcmp(token, "A_SANDOUT") == 0) )         {printf("\x1b[7m");}\
            token = strtok(NULL, " |"); \
        }\
        free(attributes); \
    }while(0)
    #define attroff(args) do{ \
        char *attributes = strdup(args); \
        char *token = strtok(attributes, " |"); \
        while (token != NULL) { \
            if (strcmp(token, "A_BOLD") == 0)           {printf("\x1b[21m");}\
            else if (strcmp(token, "A_UNDERLINE") == 0) {printf("\x1b[24m");}\
            else if (strcmp(token, "A_BLINK") == 0)     {printf("\x1b[25m");}\
            else if (strcmp(token, "A_ITALIC") == 0)    {printf("\x1b[23m");}\
            else if (strcmp(token, "A_INVIS") == 0)     {printf("\x1b[28m");}\
            else if ( (strcmp(token, "A_REVERSE") == 0) ||\
            (strcmp(token, "A_SANDOUT") == 0) )         {printf("\x1b[27m");}\
            token = strtok(NULL, " |"); \
        }\
        free(attributes); \
    }while(0)
    #define mvprintw(row, col, format, ...) do { \
        gotoxy(x+1,y+1);\
        printf(format, __VA_ARGS__); \
    } while (0)    
    #define atrr_on(args) attron(args)
    #define atrr_off(args) attroff(args)

*/
#else//*NIX
    
    #include <ncurses.h>//getch(),scanw() need -lncurses as compiler argument
    /*<ncurses.h> includes <stdio.h> */ 
    void gotoxy(int x,int y){printf("%c[%d;%df",0x1B,y,x);}
   
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
