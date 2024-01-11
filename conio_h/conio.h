#ifndef conioCompat_h
#define conioCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*Shared C libraries | START*/
#include <stdlib.h> //scanf(),printf()
#include <unistd.h> //usleep()
/*Shared C libraries | END*/

/*<conio.h> Turbo C color macros | START*/
#define delay(ms) usleep(ms * 1000)
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
#define BLINK        128
/*<conio.h> Turbo C color macros | END*/

#if defined(_WIN32) || defined(_CYGWIN_) /*OS detection | START*/

#include <conio.h>   //kbhit(),getch();
#include <windows.h> //GetConsoleScreenBufferInfo(),GetStdHandle(),SetConsoleCursorPosition(),COORD

/*Old turbo C <conio.h> functions | START*/
void clrscr() { system("cls"); };
void gotoxy(int x, int y) {
  COORD coordinate;
  coordinate.X = x;
  coordinate.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
void textbackground(int color) { // Not working as expected
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int attr = 0;
  switch (color) {
  case BLACK:
    attr = 0;
    break;
  case BLUE:
    attr = BACKGROUND_BLUE;
    break;
  case GREEN:
    attr = BACKGROUND_GREEN;
    break;
  case CYAN:
    attr = BACKGROUND_GREEN | BACKGROUND_BLUE;
    break;
  case RED:
    attr = BACKGROUND_RED;
    break;
  case MAGENTA:
    attr = BACKGROUND_RED | BACKGROUND_BLUE;
    break;
  case BROWN:
    attr = BACKGROUND_RED | BACKGROUND_GREEN;
    break;
  case LIGHTGRAY:
    attr = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
    break;
  default:
    attr = 0; // Default to black background
  }
  SetConsoleTextAttribute(hConsole, attr);
}
void textcolor(int color) { // Not working as expected
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int attr = 0;
  switch (color) {
  case BLACK:
    attr = 0;
    break;
  case BLUE:
    attr = FOREGROUND_BLUE;
    break;
  case GREEN:
    attr = FOREGROUND_GREEN;
    break;
  case CYAN:
    attr = FOREGROUND_GREEN | FOREGROUND_BLUE;
    break;
  case RED:
    attr = FOREGROUND_RED;
    break;
  case MAGENTA:
    attr = FOREGROUND_RED | FOREGROUND_BLUE;
    break;
  case BROWN:
    attr = FOREGROUND_RED | FOREGROUND_GREEN;
    break;
  case LIGHTGRAY:
    attr = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    break;
  default:
    attr =
        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; // Default to white
  }
  SetConsoleTextAttribute(hConsole, attr);
}
#define cprintf _cprintf
#define cputs _cputs
/*Old turbo C <conio.h> functions | END*/

/*My Functions | START*/
void startCompat() {}
void endCompat() {}
/*My Functions | END*/

#else                //*NIX

/*<ncurses.h> includes <stdio.h> */
#include <ncurses.h> //getch(),scanw(),
#warning "ncurses.h needs -lncurses as a compiler argument"

/*Old turbo C <conio.h> functions | START*/
void clreol() { printf("\033[K"); }

void insline() { printf("\x1b[1L"); }

void delline() { printf("\033[1M"); }

void clrscr() { system("clear"); }

void gotoxy(int x, int y) {
  printf("%c[%d;%df", 0x1B, y, x);
  fflush(stdout);
}

void textbackground(int color) { // Not tested
  int bg_color = COLOR_BLACK;
  switch (color) {
  case BLACK:
    bg_color = COLOR_BLACK;
    break;
  case BLUE:
    bg_color = COLOR_CYAN;
    break;
  case GREEN:
    bg_color = COLOR_GREEN;
    break;
  case CYAN:
    bg_color = COLOR_BLUE;
    break;
  case RED:
    bg_color = COLOR_RED;
    break;
  case MAGENTA:
    bg_color = COLOR_MAGENTA;
    break;
  case BROWN:
    bg_color = COLOR_YELLOW;
    break;
  case LIGHTGRAY:
    bg_color = COLOR_WHITE;
    break;
  case DARKGRAY:
    bg_color = COLOR_BLACK;
    break;
  case LIGHTBLUE:
    bg_color = COLOR_CYAN;
    break;
  case LIGHTGREEN:
    bg_color = COLOR_GREEN;
    break;
  case LIGHTCYAN:
    bg_color = COLOR_BLUE;
    break;
  case LIGHTRED:
    bg_color = COLOR_RED;
    break;
  case LIGHTMAGENTA:
    bg_color = COLOR_MAGENTA;
    break;
  case YELLOW:
    bg_color = COLOR_YELLOW;
    break;
  case WHITE:
    bg_color = COLOR_WHITE;
    break;
  }
  bkgd(COLOR_PAIR(bg_color));
  refresh();
}
void textcolor(int color) { // Not tested
  int fg_color = COLOR_WHITE;
  switch (color) {
  case BLACK:
    fg_color = COLOR_BLACK;
    break;
  case BLUE:
    fg_color = COLOR_CYAN;
    break;
  case GREEN:
    fg_color = COLOR_GREEN;
    break;
  case CYAN:
    fg_color = COLOR_BLUE;
    break;
  case RED:
    fg_color = COLOR_RED;
    break;
  case MAGENTA:
    fg_color = COLOR_MAGENTA;
    break;
  case BROWN:
    fg_color = COLOR_YELLOW;
    break;
  case LIGHTGRAY:
    fg_color = COLOR_WHITE;
    break;
  case DARKGRAY:
    fg_color = COLOR_BLACK;
    break;
  case LIGHTBLUE:
    fg_color = COLOR_CYAN;
    break;
  case LIGHTGREEN:
    fg_color = COLOR_GREEN;
    break;
  case LIGHTCYAN:
    fg_color = COLOR_BLUE;
    break;
  case LIGHTRED:
    fg_color = COLOR_RED;
    break;
  case LIGHTMAGENTA:
    fg_color = COLOR_MAGENTA;
    break;
  case YELLOW:
    fg_color = COLOR_YELLOW;
    break;
  case WHITE:
    fg_color = COLOR_WHITE;
    break;
  }
  attron(COLOR_PAIR(fg_color));
  refresh();
}
/*Old turbo C <conio.h> functions | END*/

/*conio.h Compatibility | START*/

#define cprintf printf
#define _cprintf cprintf
#define cputs puts
#define cscanf scanf
#define _cscanf cscanf
#define cgets gets // unsecure function
#define _cgets cgets
#define putch putchar
#define _putch putch
#define _ungetch ungetch

int kbhit() {
  int ch = 0, r = 0;
  nodelay(stdscr, TRUE);
  ch = getch();
  if (ch == ERR) { // no input
    r = FALSE;
  } else { // input
    r = TRUE;
    ungetch(ch);
  }
  nodelay(stdscr, FALSE);
  return (r);
}
#define _kbhit() kbhit()

#include <string.h> //strcat()
int nocbreak_getch() {
  raw(); // nocbreak for getch
  int ch = getch();
  cbreak();
  return ch;
}
#undef getch
#define getch() nocbreak_getch()
#define _getch() nocbreak_getch()

int getche() {
  echo();
  int ch = getch();
  noecho();
  return ch;
}
#define _getche getche
/*conio.h Compatibility | END*/

/*My Functions | START*/
void startCompat() {    // first function to be called inside main
  initscr();            // Start curses mode
  keypad(stdscr, TRUE); // enables the use of function keys,arrow keys,etc.
  noecho();             // Dont echo() output of getch(), for a similiar functionality as conio
  cbreak();             // will break with ctrl +c like on Windows
  refresh();            // Update the screen to use ncurses mode
}
void endCompat() {
  refresh();
  echo();
  fflush(stdout);
  endwin();
}
/*My Functions | END*/

#endif /*OS detection | END*/

#ifdef __cplusplus
}
#endif //__cplusplus

#endif // conioCompat_h
