#include <stdio.h>
#include <stdlib.h>//You make want to verify the uses of system()
#include "stdlib.h"

int main(){
    
    system("cls");
    printf("Terminal screen was cleared!\n");
    
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
    
    system("pause");
return 0;
}
