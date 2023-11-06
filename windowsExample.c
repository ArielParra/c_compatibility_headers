/*You need to manualy comment the windows libraries*/
//#include<windows.h> 
#include <stdio.h>
#include "windows.h"

int main(){
    SetConsoleTitle("Hello World!");
    char hello_world[]="Hello World!";
    printf("This is a string: \"%s\"\n",hello_world);
    strrev(hello_world);
    printf("This the string in reverse: \"%s\"\n",hello_world);
    
return 0;
}
