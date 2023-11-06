#include<stdio.h>//printf()
#include "ncurses.h"

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){

    initscr();            // Start curses mode
    keypad(stdscr, TRUE); // enables the use of function keys,arrow keys,etc.
    noecho();             // Dont echo() output of getch(), for a similiar functionality as conio
    cbreak();             // will break with ctrl +c like on Windows
    refresh();            // Update the screen to use ncurses mode
    clear();
    
    move(LINES/2 , COLS/2 - 22/2);
    printw("This text is centered!");refresh();
    
    getch();
    clear();
    
    char string1[100];
    char string2[100];
    
    reset_shell_mode();
        printf("To use scanf(), you need to pause the ncurses mode");refresh();
        printf("\nGive me a string: ");                              refresh();
        scanf("%s",string1);
        printf("\nThe string input using scanf=%s\n",string1);       refresh();
    reset_prog_mode();

    getch();
    clear();
 
    printw("If you dont want to pause the ncurses mode");              refresh();
    printw("\nYou can use printw() without move()");                   refresh();
    printw("\nJust be carefull, it doesnt work the same as printf()"); refresh();
    printw("\nprintw() needs refresh() after each a call");            refresh();
    printw("\nAnd you can use scanw() as a scanf() substitute");       refresh();
    printw("\nBut you will need echo() to see the typed text");        refresh();
    printw("\n(using echo()) Give me a string: ");                     refresh();
    echo(); scanw("%s",string2); noecho(); 
    printw("\nThe string input using scanw=%s\n",string2);             refresh();
    printw("\n\n(not using echo()) Give me a string: ");               refresh();
    scanw("%s",string2);
    printw("\nThe string input using scanw=%s\n",string2);             refresh();
    
    getch();
    clear();

    int ch=0, quit=0, endline=0;
    while(quit!=1){
        ch=getch();
        clear();
        move(0,0); printw("exit with 'q' key \n");                     refresh();
        move(1,0); printw("using getch(), Press any key to echo it\n");refresh();
        move(2,0); printw("You pressed: ");                            refresh();
        switch(ch){
            case KEY_UP:        move(2,14);printw("'UP (or 'K' on Windows)'\n");       refresh();break;
            case KEY_LEFT:      move(2,14);printw("'LEFT (or 'M' on Windows)'\n");     refresh();break;
            case KEY_RIGHT:     move(2,14);printw("'RIGHT (or 'H' on Windows)'\n");    refresh();break;
            case KEY_DOWN:      move(2,14);printw("'DOWN (or 'P' on Windows)'\n");     refresh();break;
            case KEY_BACKSPACE: move(2,14);printw("'BACKSPACE'\n");                    refresh();break;
            case KEY_IC:        move(2,14);printw("'INSERT (or 'R' on Windows)'\n");   refresh();break;
            case KEY_DC:        move(2,14);printw("'SUPR (or 'S' on Windows)'\n");     refresh();break;
            case KEY_PPAGE:     move(2,14);printw("'PrevPag/RePag\n");                 refresh();break;
            case KEY_NPAGE:     move(2,14);printw("'NextPag/AvPag'\n");                refresh();break;
            case KEY_END:       move(2,14);printw("'END (or 'O' on Windows)'\n");      refresh();break;
            case KEY_HOME:      move(2,14);printw("'HOME/BEG (or 'G' on Windows)'\n"); refresh();break;
            case KEY_ESC:       move(2,14);printw("'ESC'\n");                          refresh();break;
            case KEY_TAB:       move(2,14);printw("'TAB'\n");                          refresh();break;
            case KEY_SPACE:     move(2,14);printw("'SPACE BAR'\n");                    refresh();break;
            case KEY_F(1):      move(2,14);printw("'F1 (or ';' on Windows)'\n");       refresh();break;
            case KEY_F(2):      move(2,14);printw("'F2 (or '<' on Windows)'\n");       refresh();break;
            case KEY_F(3):      move(2,14);printw("'F3 (or '=' on Windows)'\n");       refresh();break;
            case KEY_F(4):      move(2,14);printw("'F4 (or '>' on Windows)'\n");       refresh();break;
            case KEY_F(5):      move(2,14);printw("'F5 (or '?' on Windows)'\n");       refresh();break;
            case KEY_F(6):      move(2,14);printw("'F6 (or '@' on Windows)'\n");       refresh();break;
            case KEY_F(7):      move(2,14);printw("'F7 (or 'A' on Windows)'\n");       refresh();break;
            case KEY_F(8):      move(2,14);printw("'F8 (or 'B' on Windows)'\n");       refresh();break;
            case KEY_F(9):      move(2,14);printw("'F9 (or 'C' on Windows)'\n");       refresh();break;
            case KEY_F(10):     move(2,14);printw("'F10 (or 'D' on Windows)'\n");      refresh();break;
            case KEY_F(11):     move(2,14);printw("'F11'\n");                          refresh();break;
            case KEY_F(12):     move(2,14);printf(" 'F12'\n");                         refresh();break;
            case KEY_ENTER:     move(2,14);printw("ENTER'\n");                         refresh();break;
            case 'q':           quit=1;                                                          break;
            default:            move(2,14);printw("'%c'\n",ch);                        refresh();break;
        }
        endline++;
    }//while()

clear();

endwin();

return 0;
}
