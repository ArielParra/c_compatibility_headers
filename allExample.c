#include<stdio.h>//printf()
#include<string.h>
#include<math.h>//floor()
#include "allCompat.h"

void hello_world_UTF8(){//graphic created using https://fsymbols.com/
    int x=getx()/2 - floor(91/2);//91 is lenght
    int y=gety()/2 - 6/2;        //6 is height
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
    Start_Compat();//while in ncurses mode, you need to use gotoxy to print
    printf(HIDE_CRSR);
    hello_world_UTF8();
    for(int i=0;i<3;i++){
        gotoxy(getx()/2 - floor(21/2), gety()/2 +3 + i);
        printf("%d seconds have elapsed\n",i+1);
        Sleep(1000);
    }

    Sleep(2000);
    sysClear();// to clear the graphics
    
    const char* colors[] = {BLACK,BLACK_LIGHT,BLACK_DARK,RED,RED_LIGHT,RED_DARK,GREEN,GREEN_LIGHT,GREEN_DARK,YELLOW,YELLOW_LIGHT,YELLOW_DARK,BLUE,BLUE_LIGHT,BLUE_DARK,MAGENTA,MAGENTA_LIGHT,MAGENTA_DARK,CYAN,CYAN_LIGHT,CYAN_DARK,WHITE,WHITE_LIGHT,WHITE_DARK};
    const char* colors_names[] = { "BLACK", "BLACK_LIGHT", "BLACK_DARK", "RED", "RED_LIGHT", "RED_DARK", "GREEN", "GREEN_LIGHT", "GREEN_DARK", "YELLOW", "YELLOW_LIGHT", "YELLOW_DARK", "BLUE", "BLUE_LIGHT", "BLUE_DARK", "MAGENTA", "MAGENTA_LIGHT", "MAGENTA_DARK", "CYAN", "CYAN_LIGHT", "CYAN_DARK", "WHITE", "WHITE_LIGHT", "WHITE_DARK" };
    

    size_t colors_size=  sizeof(colors) / sizeof(colors[0]);
    
    for(size_t i=0;i<colors_size;i++){
        printf(colors[i]);
        hola_mundo_UTF8();//fflush(stdout); IMPORTANT, but implicit because it is inside the function
        gotoxy(getx()/2 - 15, gety()/2 + 5);
        printf("TEXT COLOR:%s%s\n",CLR_RST,colors_names[i]);
        Sleep(1000);
        sysClear();
    }
    //printf(CLR_RST);//IMPLICIT
    
    const char* bg_colors[]={BG_RED,BG_GREEN,BG_YELLOW,BG_BLUE,BG_MAGENTA,BG_CYAN,BG_BLACK,BG_WHITE};
    const char* bg_colors_names[]={"BG_RED","BG_GREEN","BG_YELLOW","BG_BLUE","BG_MAGENTA","BG_CYAN","BG_BLACK","BG_WHITE"}; 
    size_t bg_colors_size = sizeof(bg_colors) / sizeof(bg_colors[0]);

    for(size_t i=0;i<bg_colors_size;i++) {
        gotoxy(getx()/2 - 15, gety()/2 + 5);
        printf("BACKGROUND COLOR: %s%s\n",bg_colors_names[i] ,bg_colors[i]);
        Sleep(1000);
        sysClear();
    }
    printf(CLR_RST);//IMPLICIT
    

    int x=getx()/2 - 40/2;//Pre definition, to align the next gotoxy()
    int y=gety()/2 - 1;
    
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
        
    Exit_Compat();//includes printf(SHOW_CRSR);
    return 0;
}


