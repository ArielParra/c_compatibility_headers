#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"ansiCompat.h"

/*Redefintion of system(), INCOMPATIBLE with legacyCompat*/
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

/*The program doesnt work as expected*/
int main() {
    // Example usage of the redefined system macro
    printf("The backgrounds doesnt work as expected :/\n");
    printf("sometimes running it a second time fix the problem,\n");
    printf("but I cant figure how to make it work :(\n");
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
    
    for(char i='0';i<='9';i++){
        strcpy(command,"color ");command[6]=i;command[7]='\0';
        system(command);
        printf("\n%s",command);
    }
    printf("\x1b[0m");
    for(char i='a';i<='f';i++){
        strcpy(command,"color ");command[6]=i;command[7]='\0';
        system(command);
        printf("\n%s",command);
    }
    printf("\n");
    return 0;
}

