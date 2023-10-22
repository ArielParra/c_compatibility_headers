#include<stdio.h>//printf()
#include<string.h>
#include<math.h>//floor()
#include<stdlib.h>
#include "ansiCompat.h"
#include "stdlibCompat.h"// Sleep()

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main(){
    setAnsi();
    const char* colors[] = { BLACK, BLACK_LIGHT, RED, RED_LIGHT, GREEN, GREEN_LIGHT, YELLOW, YELLOW_LIGHT, BLUE, BLUE_LIGHT, MAGENTA, MAGENTA_LIGHT, CYAN, CYAN_LIGHT, WHITE, WHITE_LIGHT };
    const char* colors_names[] = { "BLACK", "BLACK_LIGHT", "RED", "RED_LIGHT", "GREEN", "GREEN_LIGHT", "YELLOW", "YELLOW_LIGHT", "BLUE", "BLUE_LIGHT", "MAGENTA", "MAGENTA_LIGHT", "CYAN", "CYAN_LIGHT", "WHITE", "WHITE_LIGHT" };
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
    printf("\n%sBlinkinkg text (*NIX only)%s",BLINK_ON,BLINK_OFF);
    printf("\n%sUnderlined text %s",UNDERLINE_ON,UNDERLINE_OFF);
    printf("\n%sBold text%s", BOLD_ON,BOLD_OFF);
    printf("\n%sReversed text %s",REVERSE_ON,REVERSE_OFF);
    printf("\n(Cursor ON) Give me a string: ");
    scanf("%s",string);
    printf("\n%sYour string: '%s', ",CURSOR_OFF,string);
    printf("\n(Cursor OFF) Give me a string: ");
    scanf("%s",string);
    printf("\nYour string: '%s'",string);
    
    printf("\ncolor() function adapts the windows COLOR command\n");
    char command[3];
    for(char i='0';i<='9';i++){
            command[0]=i;command[1]='\0';
            color(command);
            printf(CLEAR_SCREEN);
            printf("\ncolor(%s)",command);
            Sleep(500);
    }
    printf(RESET_COLOR);
    for(char i='a';i<='f';i++){
            command[0]=i;command[1]='\0';
            color(command);
            printf(CLEAR_SCREEN);
            printf("\ncolor(%s)",command);
            Sleep(500);
    }
    
    for(char i='a';i<='f';i++){
        for(char j='0';j<='9';j++){
            command[0]=i;command[1]=j;command[2]='\0';
            color(command);
            printf(CLEAR_SCREEN);
            printf("\ncolor(%c%c)",command[0],command[1]);
            Sleep(500);
        }
    }
    for(char i='a';i<='f';i++){
        for(char j='0';j<='9';j++){
            command[0]=j;command[1]=i;command[2]='\0';
            color(command);
            printf(CLEAR_SCREEN);
            printf("\ncolor(%s)",command);
            Sleep(500);
        }
    }
    printf(CLEAR_SCREEN);
    
    color("  ");
    printf("\ncolor(\"  \")");
    
    //Incorrect function calls, will give compile ERROR
    color(" ");
    printf("\ncolor(\" \")");
    
    color("");
    printf("\ncolor(\"\")");
    
    printf("\n%sCursor is now ON", CURSOR_ON);
    return 0;
}

