#include<stdio.h>//printf()
#include<math.h>//floor()
#include "ncursesCompat.h"
#include "stdlibCompat.h"

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){
    startCompat();//while in ncurses mode, you need to use gotoxy to use printf()
    sysClear();

    for(int i=1;i<=3;i++){
        gotoxy(getx()/2 - floor(21/2), gety()/2 +3 + i-1);
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
        gotoxy(0,1); printf("using getch(), Press any key to echo it or press 'Q'/'q' to exit\n");
        gotoxy(0,2); printf("You pressed: ");
        switch(ch){
            case KEY_UP:        gotoxy(14,2);printf("'UP'\n");break;
            case KEY_LEFT:      gotoxy(14,2);printf("'LEFT'\n");break;
            case KEY_RIGHT:     gotoxy(14,2);printf("'RIGHT'\n");break;
            case KEY_DOWN:      gotoxy(14,2);printf("'DOWN'\n");break;
            case KEY_BACKSPACE: gotoxy(14,2);printf("'BACKSPACE'\n");break;
            case KEY_IC:        gotoxy(14,2);printf("'INSERT'\n");break;
            case KEY_DC:        gotoxy(14,2);printf("'SUPR'\n");break;
            case KEY_PPAGE:     gotoxy(14,2);printf("'PrevPag/RePag\n");break;
            case KEY_NPAGE:     gotoxy(14,2);printf("'NextPag/AvPag'\n");break;
            case KEY_END:       gotoxy(14,2);printf("'END'\n");break;
            case KEY_HOME:      gotoxy(14,2);printf("'HOME/BEG'\n");break;
            case KEY_ESC:       gotoxy(14,2);printf("'ESC'\n");break;
            case KEY_TAB:       gotoxy(14,2);printf("'TAB'\n");break;
            case KEY_SPACE:     gotoxy(14,2);printf("'SPACE BAR'\n");break;
            case KEY_F(1):      gotoxy(14,2);printf("'F1'\n");break;
            case KEY_F(2):      gotoxy(14,2);printf("'F2'\n");break;
            case KEY_F(3):      gotoxy(14,2);printf("'F3'\n");break;
            case KEY_F(4):      gotoxy(14,2);printf("'F4'\n");break;
            case KEY_F(5):      gotoxy(14,2);printf("'F5'\n");break;
            case KEY_F(6):      gotoxy(14,2);printf("'F6'\n");break;
            case KEY_F(7):      gotoxy(14,2);printf("'F7'\n");break;
            case KEY_F(8):      gotoxy(14,2);printf("'F8'\n");break;
            case KEY_F(9):      gotoxy(14,2);printf("'F9'\n");break;
            case KEY_F(10):     gotoxy(14,2);printf("'F10'\n");break;
            case KEY_F(11):     gotoxy(14,2);printf("'F11'\n");break;
            case KEY_F(12):     gotoxy(14,2);printf("'F12'\n");break;
            case KEY_ENTER:     gotoxy(14,2);printf("ENTER'\n");break;
            case 'Q':
            case 'q': quit=1;break;
            default:            gotoxy(14,2);printf("'%c'\n",ch);break;
        }
        endline++;
    }//while()
sysClear();
exitCompat();
return 0;
}
