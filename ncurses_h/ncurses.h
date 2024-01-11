#ifndef ncursesCompat_h
#define ncursesCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*Shared C library*/
#include<stdlib.h>//system()

/*shared getch() Key definitions | START*/
#define KEY_SPACE 32
#define KEY_TAB 9
#define KEY_ESC 27
/*shared getch() Key definitions | END */


#if defined(_WIN32) || defined(_CYGWIN_) /*OS detection | START*/
    #include <stdio.h>//scanf(),printf()
    #include <windows.h>//GetConsoleScreenBufferInfo(),GetStdHandle(),SetConsoleCursorPosition(),COORD
    #include <conio.h>//getch();

    /*KEYS for getch() from <conio.h> | START*/
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
    #define KEY_F(n) KEY_F_##n
    #define KEY_F_1  59     //ascii 59 is ;
    #define KEY_F_2  60     //ascii 60 is <
    #define KEY_F_3  61     //ascii 61 is =
    #define KEY_F_4  62     //ascii 62 is >
    #define KEY_F_5  63     //ascii 63 is ?
    #define KEY_F_6  64     //ascii 64 is @
    #define KEY_F_7  65     //ascii 65 is A
    #define KEY_F_8  66     //ascii 66 is B
    #define KEY_F_9  67     //ascii 67 is C
    #define KEY_F_10 68     //ascii 68 is D
    #define KEY_F_11 133     
    #define KEY_F_12 134     
    /*KEYS for getch() from <conio.h> | END*/

    /*Dummy functions |END*/
    void initscr(void){}
    void endwin(void){}
    void initrflush(void){}
    void reset_shell_mode(void){}
    void reset_prog_mode(void){}

    void cbreak(void){}
    void nocbreak(void){}
    void raw(void){}
    void *stdscr=NULL;
    /*Dummy functions | END*/

    /*Global Variables*/
    int GV_echo = 0;
    int GV_scanw = 0;

    /*ncurses functions | START*/
    void echo(){
        GV_echo = 1;
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);
    }
    void noecho(){
        GV_echo = 0;
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hStdin, &mode);
        SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));
    }

    int getmaxx(void *stdscr){
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
        return(csbi.srWindow.Right-csbi.srWindow.Left+1);
    }
    int getmaxy(void *stdscr){
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi);
        return(csbi.srWindow.Bottom-csbi.srWindow.Top+1);
    }
    #define LINES getmaxy(stdscr) 
    #define COLS getmaxx(stdscr) 
    void getmaxyx(void *stdscr, int *y, int *x) {*y=getmaxy(stdscr);*x=getmaxx(stdscr);}
    #define getmaxyx(stdscr, maxY, maxX) getmaxyx(stdscr, &maxY, &maxX) //force the use of pointers
    void move(int y,int x){
        COORD coordinate;coordinate.Y=y;coordinate.X=x;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
    }
    void addch(char ch){ printf("%c", ch); }
    void addstr(const char* str){ while (*str) { addch(*str); str++;} }
    void mvaddch(int y, int x, char ch){ move(y, x);addch(ch); }
    int  mvgetch(int y, int x){ move(y, x);return getch(); }
    void getstr(char* str){ scanf("%s", str); }
    void mvgetstr(int y, int x, char* str){ move(y, x);getstr(str); }
    void refresh(){ fflush(stdout); }
    void keypad(void *stdscr,int boolean){}
    void clrtobot(){
        CONSOLE_SCREEN_BUFFER_INFO csbi;COORD cursorPos;DWORD count;DWORD cellCount;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        cellCount = (csbi.dwSize.X - csbi.dwCursorPosition.X) + (csbi.dwSize.X * (csbi.dwSize.Y - csbi.dwCursorPosition.Y - 1));
        cursorPos.X = csbi.dwCursorPosition.X;cursorPos.Y = csbi.dwCursorPosition.Y;
        FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', cellCount, cursorPos, &count);
        FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes, cellCount, cursorPos, &count);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwCursorPosition);
    }
    void clear(){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);COORD topLeft = {0, 0};
        DWORD written;CONSOLE_SCREEN_BUFFER_INFO csbi;DWORD cellsToClear;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        cellsToClear = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputCharacter(hConsole, ' ', cellsToClear, topLeft, &written);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellsToClear, topLeft, &written);
        SetConsoleCursorPosition(hConsole, topLeft);
    }
    
    #define scanf(args...) do{ \
        if(GV_scanw == 1 && GV_echo == 0){ \
            scanf(args); noecho(); \
        }else{ \
            echo(); scanf(args); \
        } \
        GV_scanw = 0; \
    }while(0)

    #define scanw(args...) do { \
        GV_scanw = 1; \
        scanf(args); \
    }while(0)
    
    #define printw(args...) printf(args)

    #define mvprintw(x, y, format, ...) do { \
        move(y,x); \
        printf(format, __VA_ARGS__); \
    } while (0)
    /*ncurses functions | END*/

#else//*NIX

    /*<ncurses.h> includes <stdio.h> */ 
    #include <ncurses.h>
    #warning "ncurses.h needs -lncurses as a compiler argument"

    #undef  KEY_ENTER      // on ncurses is ctrl + m 
    #define KEY_ENTER '\n' // to work like Windows KEY_ENTER

#endif/*OS detection | END*/

#ifdef __cplusplus
}
#endif//__cplusplus

#endif//ncursesCompat_h
