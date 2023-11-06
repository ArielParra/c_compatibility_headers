#include<stdio.h>//printf()
#include<string.h>//strcmp()
#include "allCompat.h"

void hello_world_UTF8(){//graphic created using https://fsymbols.com/
    int x=getmaxx(stdscr)/2 - 91/2;//91 is lenght
    int y=getmaxy(stdscr)/2 - 6/2;        //6 is height
    //IMPORTANT: Use either '/n' or fflush(stdout) 
    gotoxy(x,y++);printf("██╗░░██╗███████╗██╗░░░░░██╗░░░░░░█████╗░  ░██╗░░░░░░░██╗░█████╗░██████╗░██╗░░░░░██████╗░██╗\n");
    gotoxy(x,y++);printf("██║░░██║██╔════╝██║░░░░░██║░░░░░██╔══██╗  ░██║░░██╗░░██║██╔══██╗██╔══██╗██║░░░░░██╔══██╗██║\n");
    gotoxy(x,y++);printf("███████║█████╗░░██║░░░░░██║░░░░░██║░░██║  ░╚██╗████╗██╔╝██║░░██║██████╔╝██║░░░░░██║░░██║██║\n");
    gotoxy(x,y++);printf("██╔══██║██╔══╝░░██║░░░░░██║░░░░░██║░░██║  ░░████╔═████║░██║░░██║██╔══██╗██║░░░░░██║░░██║╚═╝\n");
    gotoxy(x,y++);printf("██║░░██║███████╗███████╗███████╗╚█████╔╝  ░░╚██╔╝░╚██╔╝░╚█████╔╝██║░░██║███████╗██████╔╝██╗\n");
    gotoxy(x,y++);printf("╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝░╚════╝░  ░░░╚═╝░░░╚═╝░░░╚════╝░╚═╝░░╚═╝╚══════╝╚═════╝░╚═╝\n");
}

void hola_mundo_UTF8(){//graphic created using https://fsymbols.com/
    int height=6,lenght=81;
    int x=getmaxx(stdscr)/2 - lenght/2;
    int y=getmaxy(stdscr)/2 - height/2;
    const char* hola_mundo[]={\
    "██╗░░██╗░█████╗░██╗░░░░░░█████╗░  ███╗░░░███╗██╗░░░██╗███╗░░██╗██████╗░░█████╗░██╗",\
    "██║░░██║██╔══██╗██║░░░░░██╔══██╗  ████╗░████║██║░░░██║████╗░██║██╔══██╗██╔══██╗██║",\
    "███████║██║░░██║██║░░░░░███████║  ██╔████╔██║██║░░░██║██╔██╗██║██║░░██║██║░░██║██║",\
    "██╔══██║██║░░██║██║░░░░░██╔══██║  ██║╚██╔╝██║██║░░░██║██║╚████║██║░░██║██║░░██║╚═╝",\
    "██║░░██║╚█████╔╝███████╗██║░░██║  ██║░╚═╝░██║╚██████╔╝██║░╚███║██████╔╝╚█████╔╝██╗",\
    "╚═╝░░╚═╝░╚════╝░╚══════╝╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░╚═════╝░╚═╝░░╚══╝╚═════╝░░╚════╝░╚═╝"};
    for(size_t i=0;i<height;i++){
        gotoxy(x,y++);
        printf("%s",hola_mundo[i]);
    }
fflush(stdout);//insted of '/n' in each line
}

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){
    startCompat();//while in ncurses mode, you need to use gotoxy to print
    sysClear();

    printf(CURSOR_OFF);
    hello_world_UTF8();
    for(int i=0;i<3;i++){
        gotoxy(getmaxx(stdscr)/2 - 21/2, getmaxy(stdscr)/2 +3 + i);
        printf("%d seconds have elapsed\n",i+1);
        Sleep(1000);
    }

    Sleep(2000);
    sysClear();//to clear the graphics
    

    int x=getmaxx(stdscr)/2 - 40/2;//Pre definition, to align the next gotoxy()
    int y=getmaxy(stdscr)/2 - 1;
    
    Play_Sound("song.wav");
    gotoxy(x,y++);printf("You can use the song file name as argument");fflush(stdout);
    gotoxy(x,y++);printf("Sound Play");fflush(stdout);
    Sleep(5000);
    Stop_Sound();
    gotoxy(x,y++);printf("Sound Stop");fflush(stdout);
    Sleep(1000);
    
    y++;//add one line

    const char* song="song.wav";
    gotoxy(x,y++);printf("Or you can use a const variable as argument\n");//insted of fflush(stdou)
    Play_Sound(song);
    gotoxy(x,y++);printf("Sound Play\n");
    Sleep(5000);
    Stop_Sound();
    gotoxy(x,y++);printf("Sound Stop\n");
    Sleep(1000);
        
    endCompat();
    return 0;
}