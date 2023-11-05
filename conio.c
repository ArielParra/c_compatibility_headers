#include "conioCompat.h"

int main() {
    startCompat();
    gotoxy(10, 10);cputs("Now, let's test getch():");
    
    gotoxy(10, 12);char ch = getch(); // Wait for a keypress with echoing
    
    
    getch(); // Wait for a keypress without echoing
    clrscr(); // Clear the screen again

    gotoxy(10, 14);cputs("Now, let's test getche():");
    
    gotoxy(10, 16);char cha = getche(); // Wait for a keypress with echoing
    

    getch(); // Wait for a keypress without echoing
    clrscr(); // Clear the screen again
    exitCompat();
    return 0;
}
