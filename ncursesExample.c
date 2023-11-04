#include<stdio.h>//printf()
#include "ncursesCompat.h"
#include "stdlibCompat.h"

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){
    initscr();//while in ncurses mode, you need to use move() to use printf()
    clear();
    move(LINES/2 , COLS/2 - 22/2);
    printf("This text is centered!");
    for(int i=1;i<=3;i++){
        move(getmaxy(stdscr)/2 + i, getmaxx(stdscr)/2 - 21/2 - 1);
        printf("%d seconds have passed",i);
        Sleep(1000);
    }
    
    Sleep(2000);
    clear();// to clear the graphics
    
    char string1[100];
    char string2[100];
    
    clear();
    
    reset_shell_mode();
        printf("To use scanf(), you need to pause the ncurses mode");
        printf("\nGive me a string: "); scanf("%s",string1);
        printf("\nThe string input using scanf=%s\n",string1);
    reset_prog_mode();

    sysPause();
    clear();
 
    printw("If you dont want to pause the ncurses mode");//printw() need a refresh(), but i already include it in the header
    printw("\nYou can use printw() without move()");
    printw("\nJust be carefull, it doesnt work the same as printf()");
    printw("\nAnd you can use scanw() as a scanf() substitute");
    printw("\nGive me a string: "); scanw("%s",string2);
    printw("\nThe string input using scanw=%s\n",string2);
    
    sysPause();
    clear();

    int ch=0, quit=0, endline=0;
    while(quit!=1){
        ch=getch();
        clear();
        move(0,0); printf("exit with 'q' key \n");
        move(1,0); printf("using getch(), Press any key to echo it\n");
        move(2,0); printf("You pressed: ");
        switch(ch){
            case KEY_UP:        move(2,14);printf("'UP (or 'K' on Windows)'\n");break;
            case KEY_LEFT:      move(2,14);printf("'LEFT (or 'M' on Windows)'\n");break;
            case KEY_RIGHT:     move(2,14);printf("'RIGHT (or 'H' on Windows)'\n");break;
            case KEY_DOWN:      move(2,14);printf("'DOWN (or 'P' on Windows)'\n");break;
            case KEY_BACKSPACE: move(2,14);printf("'BACKSPACE'\n");break;
            case KEY_IC:        move(2,14);printf("'INSERT (or 'R' on Windows)'\n");break;
            case KEY_DC:        move(2,14);printf("'SUPR (or 'S' on Windows)'\n");break;
            case KEY_PPAGE:     move(2,14);printf("'PrevPag/RePag\n");break;
            case KEY_NPAGE:     move(2,14);printf("'NextPag/AvPag'\n");break;
            case KEY_END:       move(2,14);printf("'END (or 'O' on Windows)'\n");break;
            case KEY_HOME:      move(2,14);printf("'HOME/BEG (or 'G' on Windows)'\n");break;
            case KEY_ESC:       move(2,14);printf("'ESC'\n");break;
            case KEY_TAB:       move(2,14);printf("'TAB'\n");break;
            case KEY_SPACE:     move(2,14);printf("'SPACE BAR'\n");break;
            case KEY_F(1):      move(2,14);printf("'F1 (or ';' on Windows)'\n");break;
            case KEY_F(2):      move(2,14);printf("'F2 (or '<' on Windows)'\n");break;
            case KEY_F(3):      move(2,14);printf("'F3 (or '=' on Windows)'\n");break;
            case KEY_F(4):      move(2,14);printf("'F4 (or '>' on Windows)'\n");break;
            case KEY_F(5):      move(2,14);printf("'F5 (or '?' on Windows)'\n");break;
            case KEY_F(6):      move(2,14);printf("'F6 (or '@' on Windows)'\n");break;
            case KEY_F(7):      move(2,14);printf("'F7 (or 'A' on Windows)'\n");break;
            case KEY_F(8):      move(2,14);printf("'F8 (or 'B' on Windows)'\n");break;
            case KEY_F(9):      move(2,14);printf("'F9 (or 'C' on Windows)'\n");break;
            case KEY_F(10):     move(2,14);printf("'F10 (or 'D' on Windows)'\n");break;
            case KEY_F(11):     move(2,14);printf("'F11'\n");break;
            case KEY_F(12):     move(2,14);printf("'F12'\n");break;
            case KEY_ENTER:     move(2,14);printf("ENTER'\n");break;
            case 'q': quit=1;break;
            default:            move(2,14);printf("'%c'\n",ch);break;
        }
        endline++;
    }//while()
clear();
endwin();
return 0;
}
