#include<stdio.h>//printf()
#include<string.h>
#include<math.h>//floor()
/*You need to manualy comment the windows libraries*/
//#include<windows.h> 
//#include<conio.h>
//#include<stdlib.h>
#include "ansiCompat.h"
#include "legacyCompat.h"// Sleep()

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){
    const char* colors[] = {BLACK,BLACK_LIGHT,BLACK_DARK,RED,RED_LIGHT,RED_DARK,GREEN,GREEN_LIGHT,GREEN_DARK,YELLOW,YELLOW_LIGHT,YELLOW_DARK,BLUE,BLUE_LIGHT,BLUE_DARK,MAGENTA,MAGENTA_LIGHT,MAGENTA_DARK,CYAN,CYAN_LIGHT,CYAN_DARK,WHITE,WHITE_LIGHT,WHITE_DARK};
    const char* colors_names[] = { "BLACK", "BLACK_LIGHT", "BLACK_DARK", "RED", "RED_LIGHT", "RED_DARK", "GREEN", "GREEN_LIGHT", "GREEN_DARK", "YELLOW", "YELLOW_LIGHT", "YELLOW_DARK", "BLUE", "BLUE_LIGHT", "BLUE_DARK", "MAGENTA", "MAGENTA_LIGHT", "MAGENTA_DARK", "CYAN", "CYAN_LIGHT", "CYAN_DARK", "WHITE", "WHITE_LIGHT", "WHITE_DARK" };
    
    size_t colors_size=  sizeof(colors) / sizeof(colors[0]);
    
    for(size_t i=0;i<colors_size;i++){
        printf(colors[i]);
        printf("TEXT COLOR:%s%s\n",CLR_RST,colors_names[i]);
        Sleep(1000);
        printf(CLR_SCRN);
    }
    //printf(CLR_RST);//IMPLICIT
    
    const char* bg_colors[]={BG_RED,BG_GREEN,BG_YELLOW,BG_BLUE,BG_MAGENTA,BG_CYAN,BG_BLACK,BG_WHITE};
    const char* bg_colors_names[]={"BG_RED","BG_GREEN","BG_YELLOW","BG_BLUE","BG_MAGENTA","BG_CYAN","BG_BLACK","BG_WHITE"}; 
    size_t bg_colors_size = sizeof(bg_colors) / sizeof(bg_colors[0]);

    for(size_t i=0;i<bg_colors_size;i++) {
        printf("BACKGROUND COLOR: %s%s\n",bg_colors_names[i] ,bg_colors[i]);
        Sleep(1000);
        printf(CLR_SCRN);
    }
    printf(CLR_RST);//IMPLICIT

    return 0;
}


