#include<stdio.h>//printf()
#include<math.h>//floor()
#include "multiCompat.h"
#include "legacyCompat.h"

void hello_world_UTF8(){//graphic created using https://fsymbols.com/
    int x=getx()/2 - floor(91/2);//91 is lengh,floor to even
    int y=gety()/2 - 6/2;        //6 is height
    //IMPORTANT: needs '\n' or fflush(stdout);
    gotoxy(x,y++);printf("██╗░░██╗███████╗██╗░░░░░██╗░░░░░░█████╗░  ░██╗░░░░░░░██╗░█████╗░██████╗░██╗░░░░░██████╗░██╗\n");
    gotoxy(x,y++);printf("██║░░██║██╔════╝██║░░░░░██║░░░░░██╔══██╗  ░██║░░██╗░░██║██╔══██╗██╔══██╗██║░░░░░██╔══██╗██║\n");
    gotoxy(x,y++);printf("███████║█████╗░░██║░░░░░██║░░░░░██║░░██║  ░╚██╗████╗██╔╝██║░░██║██████╔╝██║░░░░░██║░░██║██║\n");
    gotoxy(x,y++);printf("██╔══██║██╔══╝░░██║░░░░░██║░░░░░██║░░██║  ░░████╔═████║░██║░░██║██╔══██╗██║░░░░░██║░░██║╚═╝\n");
    gotoxy(x,y++);printf("██║░░██║███████╗███████╗███████╗╚█████╔╝  ░░╚██╔╝░╚██╔╝░╚█████╔╝██║░░██║███████╗██████╔╝██╗\n");
    gotoxy(x,y++);printf("╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝░╚════╝░  ░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚═╝╚══════╝╚═════╝░╚═╝\n");
}

void hola_mundo_UTF8(){//graphic created using https://fsymbols.com/
    int height=6,lenght=81;
    lenght-=1;//so it become even 
    int x=getx()/2 - lenght/2;
    int y=gety()/2 - height/2;
    const char* hola_mundo[]={\
    "██╗░░██╗░█████╗░██╗░░░░░░█████╗░  ███╗░░░███╗██╗░░░██╗███╗░░██╗██████╗░░█████╗░██╗",\
    "██║░░██║██╔══██╗██║░░░░░██╔══██╗  ████╗░████║██║░░░██║████╗░██║██╔══██╗██╔══██╗██║",\
    "███████║██║░░██║██║░░░░░███████║  ██╔████╔██║██║░░░██║██╔██╗██║██║░░██║██║░░██║██║",\
    "██╔══██║██║░░██║██║░░░░░██╔══██║  ██║╚██╔╝██║██║░░░██║██║╚████║██║░░██║██║░░██║╚═╝",\
    "██║░░██║╚█████╔╝███████╗██║░░██║  ██║░╚═╝░██║╚██████╔╝██║░╚███║██████╔╝╚█████╔╝██╗",\
    "╚═╝░░╚═╝░╚════╝░╚══════╝╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░╚═════╝░╚═╝░░╚══╝╚═════╝░░╚════╝░╚═╝"};
    for(size_t i=0;i<height;i++){
        gotoxy(x,y++);
        printf(hola_mundo[i]);
    }
fflush(stdout);//insted of '/n' in each line
}

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){
    startCompat();//while in ncurses mode, you need to use gotoxy tu sue printf()
    hello_world_UTF8();
    for(int i=1;i<=3;i++){
        gotoxy(getx()/2 - floor(21/2), gety()/2 +3 + i-1);
        printf("%d seconds have passed\n",i);
        Sleep(1000);
    }
 
    sysClear();

    hola_mundo_UTF8();//fflush(stdout) needed, but implicit in the function
    for(int i=1;i<=3;i++){
        gotoxy(getx()/2 - floor(21/2), gety()/2 +3 + i-1);
        printf("%d seconds have passed\n",i);
        Sleep(1000);
    }
    
    Sleep(1000);
    sysClear();// to clear the graphics
    
    char string1[100];
    char string2[100];
    
    sysPause();
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
    printw("\nAnd you can use scanw() as a scanf() substitute");
    printw("\nGive me a string: "); scanw("%s",string2);
    printw("\nThe string input using scanw=%s",string2);
    sysPause();

    while (!_kbhit()){//no key is being pressed
        Sleep(100);
    }
    int ch = _getch();
    printw("1. You pressed the '%c' key!\n",ch);
    ch = getch();
    printw("2. You pressed the '%c' key!\n",ch);
    ch = _getch();
    printw("3. You pressed the '%c' key!\n",ch);
    ch = getch();
    printw("4. You pressed the '%c' key!\n",ch);

    Sleep(5000);
    exitCompat();
    return 0;
}


