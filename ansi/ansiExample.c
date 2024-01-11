#include <stdio.h>//printf()
#include <string.h>
#include <stdlib.h>
#include "ansi.h"
#include "../stdlib_h/stdlib.h"//sysClear(), sysPause()
#include "../windows_h/windows.h"//Sleep()


//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){
    setANSI();
    const char* colors[] = { FG_BLACK, FG_BLACK_LIGHT, FG_RED, FG_RED_LIGHT, FG_GREEN, FG_GREEN_LIGHT, FG_YELLOW, FG_YELLOW_LIGHT, FG_BLUE, FG_BLUE_LIGHT, FG_MAGENTA, FG_MAGENTA_LIGHT, FG_CYAN, FG_CYAN_LIGHT, FG_WHITE, FG_WHITE_LIGHT };
    const char* colors_names[] = { "FG_BLACK", "FG_BLACK_LIGHT", "FG_RED", "FG_RED_LIGHT", "FG_GREEN", "FG_GREEN_LIGHT", "FG_YELLOW", "FG_YELLOW_LIGHT", "FG_BLUE", "FG_BLUE_LIGHT", "FG_MAGENTA", "FG_MAGENTA_LIGHT", "FG_CYAN", "FG_CYAN_LIGHT", "FG_WHITE", "FG_WHITE_LIGHT" };
    size_t colors_size = sizeof(colors) / sizeof(colors[0]);

    printf(CLEAR_SCREEN);
    for(size_t i=0;i<colors_size;i++){
        printf(colors[i]);
        printf("TEXT_COLOR:%s%s\n",RESET_COLOR,colors_names[i]);
        Sleep(800);
        printf(CLEAR_SCREEN);
    }
    //printf(RESET_COLOR);//IMPLICIT
    
    const char* bg_colors[] = {BG_BLACK, BG_BLACK_LIGHT, BG_RED, BG_RED_LIGHT, BG_GREEN, BG_GREEN_LIGHT, BG_YELLOW, BG_YELLOW_LIGHT, BG_BLUE, BG_BLUE_LIGHT, BG_MAGENTA, BG_MAGENTA_LIGHT, BG_CYAN, BG_CYAN_LIGHT, BG_WHITE, BG_WHITE_LIGHT};
    const char* bg_colors_names[] = {"BG_BLACK", "BG_BLACK_LIGHT", "BG_RED", "BG_RED_LIGHT", "BG_GREEN", "BG_GREEN_LIGHT", "BG_YELLOW", "BG_YELLOW_LIGHT", "BG_BLUE", "BG_BLUE_LIGHT", "BG_MAGENTA", "BG_MAGENTA_LIGHT", "BG_CYAN", "BG_CYAN_LIGHT", "BG_WHITE", "BG_WHITE_LIGHT"};
    size_t bg_colors_size = sizeof(colors) / sizeof(colors[0]);

    for(size_t i=0;i<bg_colors_size;i++) {
        printf("%s",bg_colors[i]);
        printf(CLEAR_SCREEN);//IDK why but this fixes the Background and text sync issues
        printf("BACKGROUND COLOR: %s\n",bg_colors_names[i]);
        Sleep(800);
    }

    char string[100];
    printf("%s%s",RESET_COLOR,CLEAR_SCREEN);
    printf("\n%s*Blinkinkg text%s",BLINK_ON,BLINK_OFF);
    printf("\n%sCrossed text%s",CROSS_ON,CROSS_OFF);
    printf("\nInvisible text: '%sHello World!%s'",INVISIBLE_ON,INVISIBLE_OFF);
    printf("\n%sDIM text%s",DIM_ON,DIM_OFF);
    printf("\n%sReversed text %s",REVERSE_ON,REVERSE_OFF);
    printf("\n%sITALIC text%s",ITALIC_ON,ITALIC_OFF);
    printf("\n%sUnderlined text %s",UNDERLINE_ON,UNDERLINE_OFF);
    printf("\n%sBold text%s", BOLD_ON,BOLD_OFF);
    printf("\n%s%s%s%s%s%s%s%sCombination text %s%s%s%s%s%s%s%s",BLINK_ON,CROSS_ON,REVERSE_ON,DIM_ON,ITALIC_ON,UNDERLINE_ON,BOLD_ON,REVERSE_ON, BLINK_OFF,CROSS_OFF,REVERSE_OFF,DIM_OFF,ITALIC_OFF,UNDERLINE_OFF,BOLD_OFF,REVERSE_OFF);
    printf("\n(Cursor ON) Give me a string: ");
    scanf("%s",string);
    printf("\n%sYour string: '%s', ",CURSOR_OFF,string);
    printf("\n(Cursor OFF) Give me a string: ");
    scanf("%s",string);
    printf("\nYour string: '%s'",string);
    printf("%s",CURSOR_ON);
    
    printf(RESET_TEXT);
    sysPause();
    sysClear();
    printf("\n%sCursor is now ON", CURSOR_ON);
    return 0;
}
