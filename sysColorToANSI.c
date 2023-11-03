#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ansiCompat.h"
#include"stdlibCompat.h"


void color(const char *arg){

    printf(RESET_COLOR); //by default

    /*ForeGround (text color)*/
    //if( isdigit(arg[0]) || isalpha(arg[0]) ){ // uses <ctype.h>
    if( ( arg[0] >= '0' && arg[0] <= '9') || ( (arg[0] >= 'a' && arg[0] <= 'z') || (arg[0] >= 'A' && arg[0] <= 'Z') ) ){
        switch (arg[0]) { 
            case '0': printf(FG_BLACK); break; 
            case '1': printf(FG_BLUE); break; 
            case '2': printf(FG_GREEN); break; 
            case '3': printf(FG_CYAN); break;        //Windows aqua
            case '4': printf(FG_RED); break; 
            case '5': printf(FG_MAGENTA); break;     //Windows purple
            case '6': printf(FG_YELLOW); break; 
            case '7': printf(FG_WHITE); break; 
            case '8': printf(FG_BLACK_LIGHT); break; //Windows purple
            case '9': printf(FG_BLUE_LIGHT); break; 
            case 'a': case 'A': printf(FG_GREEN_LIGHT); break; 
            case 'b': case 'B': printf(FG_CYAN_LIGHT); break; 
            case 'c': case 'C': printf(FG_RED_LIGHT); break; 
            case 'd': case 'D': printf(FG_MAGENTA_LIGHT); break; 
            case 'e': case 'E': printf(FG_YELLOW_LIGHT); break; 
            case 'f': case 'F': printf(FG_WHITE_LIGHT); break; 
            default: printf(RESET_COLOR); //for unknown argument 
        }//siwtch
    }//if

    /*BackGround*/
    //if(arg[1]!='\0' && arg[2] == '\0' && ( isdigit(arg[1]) || isalpha(arg[1]) ) ){ // uses <ctype.h> 
    if(arg[1] != '\0' && arg[2] == '\0' && ( (arg[1] >= '0' && arg[1] <= '9') || ( (arg[1] >= 'a' && arg[1] <= 'z') || (arg[1] >= 'A' && arg[1] <= 'Z') ) ) ) {
        switch (arg[1]) { 
            case '0': printf(BG_BLACK); break; 
            case '1': printf(BG_BLUE); break; 
            case '2': printf(BG_GREEN); break; 
            case '3': printf(BG_CYAN); break;        //Windows aqua
            case '4': printf(BG_RED); break; 
            case '5': printf(BG_MAGENTA); break;     //Windows purple
            case '6': printf(BG_YELLOW); break; 
            case '7': printf(BG_WHITE); break; 
            case '8': printf(BG_BLACK_LIGHT); break; //Windows gray
            case '9': printf(BG_BLUE_LIGHT); break; 
            case 'a': case 'A': printf(BG_GREEN_LIGHT); break; 
            case 'b': case 'B': printf(BG_CYAN_LIGHT); break; 
            case 'c': case 'C': printf(BG_RED_LIGHT); break; 
            case 'd': case 'D': printf(BG_MAGENTA_LIGHT); break; 
            case 'e': case 'E': printf(BG_YELLOW_LIGHT); break; 
            case 'f': case 'F': printf(BG_WHITE_LIGHT); break; 
            default: printf(RESET_COLOR); //for unknown argument
        }//switch 
    }//if
}//color()

/*Redefintion of system(), INCOMPATIBLE with stdlibCompat*/
#define system(cmd) do { \
    if (strncmp(cmd, "color", 5) == 0 || strncmp(cmd, "COLOR", 5) == 0) { \
        if(cmd[5] == '\0') { \
            /* Reset colors if no argument is provided */ \
            printf("\x1b[0m"); \
        }else if(cmd[5] == ' ' && (isdigit(cmd[6]) || isalpha(cmd[6]) ) &&  cmd[7]=='\0'){ \
             char arg[3];\
             arg[0]=cmd[6];arg[1]='\0';\
             color(arg);\
        }else if(cmd[5] == ' ' && ( isdigit(cmd[6]) || isalpha(cmd[6]) ) && (isdigit(cmd[7]) || isalpha(cmd[7]) ) ){ \
            /*BackGround*/\
            char arg[3];\
            arg[0]=cmd[6];arg[1]=cmd[7];arg[2]='\0';\
            color(arg);\
        } \
    } \
} while (0)

#include <windows.h>

/*The program doesnt work as expected*/
int main() {
    setAnsi();
    printf(CLEAR_SCREEN);
    // Example usage of the redefined system macro
    printf("The backgrounds doesnt work as expected :/\n");
    printf("sometimes running it a second time fix the problem,\n");
    printf("but I cant figure how to make it work :(\n");
    char command[8];
    
    /*Two arguments*/
    for(char i='0';i<='9';i++){
        for(char j='a';j<='f';j++){
            strcpy(command,"color ");command[6]=i;command[7]=j;command[8]='\0';
            system(command);
            printf(CLEAR_SCREEN);// to make it work
            printf("Two arguments\n%s",command);
            Sleep(500);
        }
    }
    for(char i='0';i<='9';i++){
        for(char j='a';j<='f';j++){
            strcpy(command,"color ");command[6]=j;command[7]=i;command[8]='\0';
            system(command);
            printf(CLEAR_SCREEN);
            printf("Two arguments\n%s",command);
            Sleep(500);
        }
    }
    
    /*One argument*/
    for(char i='0';i<='9';i++){
        strcpy(command,"color ");command[6]=i;command[7]='\0';
        system(command);
        printf(CLEAR_SCREEN);
        printf("One argument\n%s",command);
        Sleep(500);
    }
    printf("\x1b[0m");
    for(char i='a';i<='f';i++){
        strcpy(command,"color ");command[6]=i;command[7]='\0';
        system(command);
        printf(CLEAR_SCREEN);
        printf("One argument\n%s",command);
        Sleep(500);
    }

    /*No argument*/
    system("color");
    printf("No argument\ncolor");
    printf("\n");
    return 0;
}

