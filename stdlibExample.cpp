/*You need to manualy comment the windows libraries*/
//#include<windows.h> 
//#include<conio.h>
#include<stdio.h>
#include<stdlib.h>//You make want to verify the uses of system()
#include"stdlibCompat.h"

//int main(int argc,char *argv[]){
//int main(int argc,char **argv){
//int main(void){
int main() {
    char hello_world[]="Hello World!";
    printf("This is a string: \"%s\"\n",hello_world);
    strrev(hello_world);
    printf("This the string in reverse: \"%s\"\n",hello_world);

    system("pause");
    
    system("cls");
    printf("Terminal screen was cleared!\n");
    
    Sleep(1000);
    printf("1000 ms have passed!\n");
    
    int base[] = {2, 8, 10, 16};

    int numI=123;
    char stringI[100];
    printf("\nThis is an int num: %d\n", numI);
    for(size_t i=0;i<4;i++){
        itoa(numI,stringI,base[i]);
        printf("this the string in base %d: \"%s\"\n", base[i],stringI);
    } 

    long numL=456;
    char stringL[100];
    printf("\nThis is a long num: %ld\n", numL);
    for(size_t i =0;i<4;i++){
        ltoa(numL,stringL,base[i]);
        printf("this the string in base %d: \"%s\"\n", base[i],stringL);
    }

    unsigned long int numU=789;
    char stringU[100];
    printf("\nThis is a unsigned long num: %lu\n", numU);
    
    for(size_t i=0;i<4;i++){
        ultoa(numU,stringU,base[i]);
        printf("this the string in base %d: \"%s\"\n", base[i],stringU);
    }
    
return 0;
}