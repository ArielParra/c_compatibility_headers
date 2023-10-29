#include<stdio.h>//printf()
#include "ncursesCompat.h"
#include "stdlibCompat.h"

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){
    startCompat();//while in ncurses mode, you need to use gotoxy to use printf()
    sysClear();

    for(int i=1;i<=3;i++){
        gotoxy(getmaxx(stdscr)/2 - 21/2, getmaxy(stdscr)/2 +3 + i-1);
        printf("%d seconds have passed\n",i);
        Sleep(1000);
    }
    
    Sleep(2000);
    sysClear();// to clear the graphics
    
    char string1[100];
    char string2[100];
    
    sysClear();
    
    pauseCompat();
        printf("To use scanf(), you need to pause the ncurses mode");
        printf("\nGive me a string: "); scanf("%s",string1);
        printf("\nThe string input using scanf=%s\n",string1);
    resumeCompat();

    sysPause();
    sysClear();
 
    printw("If you dont want to pause the ncurses mode");//printw() need a refresh(), but i already include it in the header
    printw("\nYou can use printw() without gotoxy()");
    printw("\nJust be carefull, it doesnt work the same as printf()");
    printw("\nAnd you can use scanw() as a scanf() substitute");
    printw("\nGive me a string: "); scanw("%s",string2);
    printw("\nThe string input using scanw=%s\n",string2);
    
    sysPause();
    sysClear();

    printw("Press any key to quit kbhit()");   
    int ch=0;
    while (!_kbhit()){//no key is being pressed
        //will wait
    }
    sysClear();
    printw("You pressed any key! :D");
    gotoxy(0,1);printf("\n");
    sysPause();
    
    int quit=0,endline=0;
    while(quit!=1){
        ch=getch();
        sysClear();
        gotoxy(0,0); printf("you cant quit wiht ctrl + c on geth() mode, so exit with 'q' key \n");
        gotoxy(0,1); printf("using getch(), Press any key to echo it\n");
        gotoxy(0,2); printf("You pressed: ");
        switch(ch){
            case KEY_UP:        gotoxy(14,2);printf("'UP (or 'K' on Windows)'\n");break;
            case KEY_LEFT:      gotoxy(14,2);printf("'LEFT (or 'M' on Windows)'\n");break;
            case KEY_RIGHT:     gotoxy(14,2);printf("'RIGHT (or 'H' on Windows)'\n");break;
            case KEY_DOWN:      gotoxy(14,2);printf("'DOWN (or 'P' on Windows)'\n");break;
            case KEY_BACKSPACE: gotoxy(14,2);printf("'BACKSPACE'\n");break;
            case KEY_IC:        gotoxy(14,2);printf("'INSERT (or 'R' on Windows)'\n");break;
            case KEY_DC:        gotoxy(14,2);printf("'SUPR (or 'S' on Windows)'\n");break;
            case KEY_PPAGE:     gotoxy(14,2);printf("'PrevPag/RePag\n");break;
            case KEY_NPAGE:     gotoxy(14,2);printf("'NextPag/AvPag'\n");break;
            case KEY_END:       gotoxy(14,2);printf("'END (or 'O' on Windows)'\n");break;
            case KEY_HOME:      gotoxy(14,2);printf("'HOME/BEG (or 'G' on Windows)'\n");break;
            case KEY_ESC:       gotoxy(14,2);printf("'ESC'\n");break;
            case KEY_TAB:       gotoxy(14,2);printf("'TAB'\n");break;
            case KEY_SPACE:     gotoxy(14,2);printf("'SPACE BAR'\n");break;
            case KEY_F1:        gotoxy(14,2);printf("'F1 (or ';' on Windows)'\n");break;
            case KEY_F2:        gotoxy(14,2);printf("'F2 (or '<' on Windows)'\n");break;
            case KEY_F3:        gotoxy(14,2);printf("'F3 (or '=' on Windows)'\n");break;
            case KEY_F4:        gotoxy(14,2);printf("'F4 (or '>' on Windows)'\n");break;
            case KEY_F5:        gotoxy(14,2);printf("'F5 (or '?' on Windows)'\n");break;
            case KEY_F6:        gotoxy(14,2);printf("'F6 (or '@' on Windows)'\n");break;
            case KEY_F7:        gotoxy(14,2);printf("'F7 (or 'A' on Windows)'\n");break;
            case KEY_F8:        gotoxy(14,2);printf("'F8 (or 'B' on Windows)'\n");break;
            case KEY_F9:        gotoxy(14,2);printf("'F9 (or 'C' on Windows)'\n");break;
            case KEY_F10:       gotoxy(14,2);printf("'F10 (or 'D' on Windows)'\n");break;
            case KEY_F11:       gotoxy(14,2);printf("'F11'\n");break;
            case KEY_F12:       gotoxy(14,2);printf("'F12'\n");break;
            case KEY_ENTER:     gotoxy(14,2);printf("ENTER'\n");break;
            case 'q': quit=1;break;
            default:            gotoxy(14,2);printf("'%c'\n",ch);break;
        }
        endline++;
    }//while()
sysClear();
exitCompat();
return 0;
}
