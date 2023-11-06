#include<stdio.h>//printf()
/*You need to manualy comment the windows libraries*/
//#include<windows.h> 
//#include<conio.h>
//#include<stdlib.h>
#include "windowsCompat.h"//Sleep()
#include "PlaySound.h"//PlaySound()

int main(){
   
 printf("You can use the original PlaySound command\n");
    Sleep(2000);
    PlaySound("song.wav",NULL, SND_ASYNC);
    printf("Sound Play\n");
    Sleep(5000);
    PlaySoundA(NULL, 0, 0);
    printf("Sound Stop\n\n");
    Sleep(1000);
    
    const char* song="song.wav";
    printf("Or you can call Play_Sound() with a const string\n");
    Sleep(2000);
    Play_Sound(song);
    printf("Sound Play\n");
    Sleep(5000);
    Stop_Sound();
    printf("Sound Stop\n");
    Sleep(1000);
        
    return 0;
}


