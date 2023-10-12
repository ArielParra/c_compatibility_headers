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
    startCompat();//while in ncurses mode, you need to use gotoxy to print
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

    

    Sleep(2000);
    sysClear();// to clear the graphics

    exitCompat();//includes printf(SHOW_CRSR);
    return 0;
}


