#include <stdio.h>
#include"ansiCompat.h"
    
int main() {
    // Example usage of the redefined system macro
    char command[2];
    for(char i='0';i<='9';i++){
        for(char j='a';j<='f';j++){
            command[0]=i;command[1]=j;command[2]='\0';
            color(command);
            printf("\ncolor(%s)",command);
        }
    }
    for(char i='0';i<='9';i++){
        for(char j='a';j<='f';j++){
            command[0]=j;command[1]=i;command[2]='\0';
            color(command);
            printf("\ncolor(%s)",command);

        }
    }
    
    for(char i='0';i<='9';i++){
            command[0]=i;command[1]='\0';
            color(command);
            printf("\ncolor(%s)",command);
    }
    printf("\x1b[0m");
    for(char i='a';i<='f';i++){
            command[0]=i;command[1]='\0';
            color(command);
            printf("\ncolor(%s)",command);
    }
    printf("\n");
    return 0;
}

