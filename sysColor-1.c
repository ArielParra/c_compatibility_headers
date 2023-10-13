
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ansiCompat.h"

#if defined(_WIN32) || defined(__CYGWIN__)
#else
#define system(cmd) do { \
    printf("\x1b[0m"); \
    if (strncmp(cmd, "color", 5) == 0 || strncmp(cmd, "COLOR", 5) == 0) { \
        if(cmd[5] == '\0') { \
            /* Reset colors if no argument is provided */ \
            printf("\x1b[0m"); \
        }else if(cmd[5] == ' ' && (isdigit(cmd[6]) || isalpha(cmd[6]) ) && ( isalpha(cmd[7]) || isdigit(cmd[7]) ) ){ \
            /*ForeGround*/\
            switch (cmd[6]) { \
                case '0': printf(BLACK); break; \
                case '1': printf(BLUE); break; \
                case '2': printf(GREEN); break; \
                case '3': printf(CYAN); break; \
                case '4': printf(RED); break; \
                case '5': printf(MAGENTA); break; \
                case '6': printf(YELLOW); break; \
                case '7': printf(WHITE); break; \
                case '8': printf(WHITE_DARK); break; \
                case '9': printf(BLUE_LIGHT); break; \
                case 'a': case 'A': printf(GREEN_LIGHT); break; \
                case 'b': case 'B': printf(CYAN_LIGHT); break; \
                case 'c': case 'C': printf(RED_LIGHT); break; \
                case 'd': case 'D': printf(MAGENTA_LIGHT); break; \
                case 'e': case 'E': printf(YELLOW_LIGHT); break; \
                case 'f': case 'F': printf(WHITE_LIGHT); break; \
                default: printf("\x1b[0m"); /* Reset colors for unknown argument */ \
            } \
            /*BackGround*/\
            switch (cmd[7]) { \
                case '0': printf(BG_BLACK); break; \
                case '1': printf(BG_BLUE); break; \
                case '2': printf(BG_GREEN); break; \
                case '3': printf(BG_CYAN); break; \
                case '4': printf(BG_RED); break; \
                case '5': printf(BG_MAGENTA); break; \
                case '6': printf(BG_YELLOW); break; \
                case '7': printf(BG_WHITE); break; \
                case '8': printf(BG_WHITE_DARK); break; \
                case '9': printf(BG_BLUE_LIGHT); break; \
                case 'a': case 'A': printf(BG_GREEN_LIGHT); break; \
                case 'b': case 'B': printf(BG_CYAN_LIGHT); break; \
                case 'c': case 'C': printf(BG_RED_LIGHT); break; \
                case 'd': case 'D': printf(BG_MAGENTA_LIGHT); break; \
                case 'e': case 'E': printf(BG_YELLOW_LIGHT); break; \
                case 'f': case 'F': printf(BG_WHITE_LIGHT); break; \
                default: printf("\x1b[0m"); /* Reset colors for unknown argument */ \
            } \
        } \
    } \
} while (0)

#endif

int main(){
    char command[8];
    for(char i='0';i<='9';i++){
        for(char j='a';j<='f';j++){
            strcpy(command,"color ");command[6]=i;command[7]=j;command[8]='\0';
            system(command);
            printf("\n%s",command);
        }
    }
    for(char i='0';i<='9';i++){
        for(char j='a';j<='f';j++){
            strcpy(command,"color ");command[6]=j;command[7]=i;command[8]='\0';
            system(command);
            printf("\n%s",command);
        }
    }
    printf("%s\n",CLR_RST);
return 0;
}
