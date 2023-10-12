#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define system(cmd) do { \
    if (strncmp(cmd, "color", 5) == 0 || strncmp(cmd, "COLOR", 5) == 0) { \
        if (cmd[5] == '\0') { \
            /* Reset colors if no argument is provided */ \
            printf("\x1b[0m"); \
        } else if (cmd[5] == ' ' && (isdigit(cmd[6]) || isalpha(cmd[6])) && (isdigit(cmd[7]) || isalpha(cmd[7])) ) { \
            char fg[4], bg[4]; \
            /* Text Color */ \
            switch (cmd[6]) { \
                case '0': strcpy(fg, "30"); break; /* Black */ \
                case '1': strcpy(fg, "34"); break; /* Blue */ \
                case '2': strcpy(fg, "32"); break; /* Green */ \
                case '3': strcpy(fg, "36"); break; /* Cyan */ \
                case '4': strcpy(fg, "31"); break; /* Red */ \
                case '5': strcpy(fg, "35"); break; /* Purple */ \
                case '6': strcpy(fg, "33"); break; /* Yellow */ \
                case '7': strcpy(fg, "37"); break; /* White */ \
                case '8': strcpy(fg, "90"); break; /* Light Gray */ \
                case '9': strcpy(fg, "97"); break; /* Light White */ \
                case 'a': case 'A': strcpy(fg, "92"); break; /* Light Green */ \
                case 'b': case 'B': strcpy(fg, "96"); break; /* Light Cyan */ \
                case 'c': case 'C': strcpy(fg, "91"); break; /* Light Red */ \
                case 'd': case 'D': strcpy(fg, "95"); break; /* Light Purple */ \
                case 'e': case 'E': strcpy(fg, "93"); break; /* Light Yellow */ \
                case 'f': case 'F': strcpy(fg, "97"); break; /* Light White */ \
                default: strcpy(bg, "0"); break; /* Reset colors for unknown argument */ \
            } \
            /* Background Color */ \
            switch (cmd[7]) { \
                case '0': strcpy(bg, "40"); break; /* Black */ \
                case '1': strcpy(bg, "44"); break; /* Blue */ \
                case '2': strcpy(bg, "42"); break; /* Green */ \
                case '3': strcpy(bg, "46"); break; /* Cyan */ \
                case '4': strcpy(bg, "41"); break; /* Red */ \
                case '5': strcpy(bg, "45"); break; /* Purple */ \
                case '6': strcpy(bg, "43"); break; /* Yellow */ \
                case '7': strcpy(bg, "47"); break; /* White */ \
                case '8': strcpy(bg, "100"); break; /* Light Gray */ \
                case '9': strcpy(bg, "107"); break; /* Light White */ \
                case 'a': case 'A': strcpy(bg, "102"); break; /* Light Green */ \
                case 'b': case 'B': strcpy(bg, "106"); break; /* Light Cyan */ \
                case 'c': case 'C': strcpy(bg, "101"); break; /* Light Red */ \
                case 'd': case 'D': strcpy(bg, "105"); break; /* Light Purple */ \
                case 'e': case 'E': strcpy(bg, "103"); break; /* Light Yellow */ \
                case 'f': case 'F': strcpy(bg, "107"); break; /* Light White */ \
                default: strcpy(bg, "0"); break; /* Reset colors for unknown argument */ \
            } \
            printf("\x1b[%s;%sm", fg, bg); \
        } \
    } else { \
        printf(cmd); /* Execute other commands using the default system call */ \
    } \
} while (0)

int main() {
    // Example usage of the redefined system macro
    char command[8];
    for(char i='0';i<='9';i++){
        for(char j='a';j<='f';j++){
            strcpy(command,"color ");command[6]=i;command[7]=j;command[8]='\0';
            system(command);
            printf("%s\x1b[0m\n",command);
            
        }
    }
    for(char i='0';i<='9';i++){
        for(char j='a';j<='f';j++){
            strcpy(command,"color ");command[6]=j;command[7]=i;command[8]='\0';
            system(command);
            printf("%s\x1b[0m\n",command);
        }
    }
    printf("\x1b[0m");


    return 0;
}

