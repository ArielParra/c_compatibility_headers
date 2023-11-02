#ifndef ncursesCompat_h
#define ncursesCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*Shared C library*/
#include<stdlib.h>//system()

/*shared getch() Key definitions  | START*/
#define KEY_SPACE 32
#define KEY_TAB 9
#define KEY_ESC 27
/*shared getch() Key definitions | END */


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
    void textbackground(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        csbi.wAttributes &= ~(BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
        csbi.wAttributes |= (color << 4);
        SetConsoleTextAttribute(hConsole, csbi.wAttributes);
    }
    void textcolor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        csbi.wAttributes &= ~(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
        csbi.wAttributes |= color;
        SetConsoleTextAttribute(hConsole, csbi.wAttributes);
    }
    void delay(int ms){Sleep(ms);} 
    #define cputs _cputs
    /*Old turbo C <conio.h> functions | END*/

    /*KEYS for getch() from <conio.h> | START*/
    //to be compatible with ncurses definitions
    #define KEY_LEFT 75     //ascii 75 is K
    #define KEY_RIGHT 77    //ascii 77 is M
    #define KEY_UP 72       //ascii 72 is H
    #define KEY_DOWN 80     //ascii 80 is P
    #define KEY_ENTER 13    //'\n' on ncurses    
    #define KEY_BACKSPACE 8 
    #define KEY_HOME 71     //ascii 71 is G
    #define KEY_END 79      //ascii 79 is O
    #define KEY_IC 82       //ascii 82 is R
    #define KEY_DC 83       //ascii 83 is S
    #define KEY_PPAGE 73    //ascii 73 is I
    #define KEY_NPAGE 81    //ascii 81 is Q
    //You cant use parenthesis on Windows so KEY_F(1) will be KEY_F1
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
    /*KEYS for getch() from <conio.h> | END*/

    /*My Functions | START*/
    void startCompat(){}
    void exitCompat(){}
    /*My Functions | START*/


    /*Dummy functions |END*/
    void initrflush(void){}
    void reset_shell_mode(void){}
    void reset_prog_mode(void){}
    void echo(void){}
    void noecho(void){}
    void cbreak(void){}
    void nocbreak(void){}
    void raw(void){}
    void *stdscr=NULL;
    /*Dummy functions | END*/

    /*ncurses functions | START*/
    int getmaxx(void *stdscr){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Right-csbi.srWindow.Left);}
    int getmaxy(void *stdscr){CONSOLE_SCREEN_BUFFER_INFO csbi;GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);return(csbi.srWindow.Bottom-csbi.srWindow.Top);}
    #define LINES getmaxy(stdscr) 
    #define COLS getmaxx(stdscr) 
    void getmaxyx(void *stdscr, int *y, int *x) {*y=getmaxy(stdscr);*x=getmaxx(stdscr);}
    #define getmaxyx(stdscr, maxY, maxX) getmaxyx(stdscr, &maxY, &maxX) //force the use of pointers
    #define move(y,x) gotoxy(x,y)
    void addch(char ch) {printf("%c", ch);}
    void addstr(const char* str) { while (*str) { addch(*str); str++;} }
    void mvaddch(int y, int x, char ch) {gotoxy(x, y);addch(ch);}
    int  mvgetch(int y, int x) {gotoxy(x, y);return getch();}
    void getstr(char* str) {scanf("%s", str);}
    void mvgetstr(int y, int x, char* str) {gotoxy(x, y);getstr(str);}
    void refresh(){fflush(stdout);}
    //void initscr(){startCompat();}
    //void endwin(){exitCompat();}
    void keypad(void *stdscr,int boolean){}
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
    /*ncurses functions | END*/

#else//*NIX

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

    int nocbreak_getch() {
        raw();
        int ch = getch();
        cbreak();
        return ch;
    }
    #undef  getch
    #define getch() nocbreak_getch()
    #define _getch() nocbreak_getch()
    
    /*getch() Key definitions*/
    #undef  KEY_ENTER // on ncurses is ctrl + m 
    #define KEY_ENTER '\n' //to work like on windows
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

    #define printw(args...) do{printw(args);refresh();}while(0)         // to work similar to printf
    #define scanw(args...) do{echo();scanw(args);noecho();}while(0)     // to work similar to scanf
    #define cprintf(format, ...)do { printf(format, __VA_ARGS__); } while (0)
    #define _cprintf cprintf
    /*conio.h Compatibility | END*/


#endif/*OS detection | END*/

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//ncursesCompat_h
