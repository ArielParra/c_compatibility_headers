#include "conio.h"//startCompat(), endCompat(), gotoxy(), getch(), clrscr()

int main() {
    startCompat();

    gotoxy(10, 10);cputs("Now, let's test getch():");
    gotoxy(10, 12);char ch = getch();

    getch(); 
    clrscr();

    gotoxy(10, 14);cputs("Now, let's test getche():");
    gotoxy(10, 16);char cha = getche();

    getch(); 
    clrscr();
    
    endCompat();
    return 0;
}
