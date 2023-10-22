#include<stdio.h>//printf()
/*You need to manualy comment the windows libraries*/
//#include<windows.h> 
//#include<conio.h>
//#include<stdlib.h>
#include "Play_Sound.h"
#include "stdlibCompat.h"

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){
   
    printf("You can use the song file name as argument\n");
    Sleep(2000);
    Play_Sound("song.wav");
    printf("Sound Play\n");
    Sleep(5000);
    Stop_Sound();
    printf("Sound Stop\n\n");
    Sleep(1000);
    
    const char* song="song.wav";
    printf("Or you can use a const variable as argument\n");//insted of fflush(stdou)
    Sleep(2000);
    Play_Sound(song);
    printf("Sound Play\n");
    Sleep(5000);
    Stop_Sound();
    printf("Sound Stop\n");
    Sleep(1000);
        
    return 0;
}


