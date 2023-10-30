/*<ncurses.h> atron(), atroff() functions implentations on Windows*/
    /*ncurses colors for pairs and attr*/

    #warning "atron(), atroff() implemntations needs previous call to setANSI() function to work on CMD"
    #define A_BOLD      1
    #define A_UNDERLINE 4
    #define A_BLINK     5
    #define A_ITALIC    3
    #define A_INVIS     8
    #define A_REVERSE   7
    #define A_SANDOUT   A_REVERSE

    /*ncurses colors*/
    #define COLOR_BLACK     0
    #define COLOR_RED       1
    #define COLOR_GREEN     2
    #define COLOR_YELLOW    3
    #define COLOR_BLUE      4
    #define COLOR_MAGENTA   5
    #define COLOR_CYAN      6
    #define COLOR_WHITE     7
    
    void attron(unsigned int attributes){
        if (attributes & A_BOLD)      printf("\x1b[%dm",A_BOLD);
        if (attributes & A_UNDERLINE) printf("\x1b[%dm",A_UNDERLINE);
        if (attributes & A_BLINK)     printf("\x1b[%dm",A_BLINK);
        if (attributes & A_ITALIC)    printf("\x1b[%dm",A_ITALIC);
        if (attributes & A_INVIS)     printf("\x1b[%dm",A_INVIS);
        if (attributes & A_REVERSE)   printf("\x1b[%dm",A_REVERSE);
    }
    void attroff(unsigned int attributes){
        if (attributes & A_BOLD)      printf("\x1b[%dm",A_BOLD+21);
        if (attributes & A_UNDERLINE) printf("\x1b[%dm",A_UNDERLINE+20);
        if (attributes & A_BLINK)     printf("\x1b[%dm",A_BLINK+20);
        if (attributes & A_ITALIC)    printf("\x1b[%dm",A_ITALIC+20);
        if (attributes & A_INVIS)     printf("\x1b[%dm",A_INVIS+20);
        if (attributes & A_REVERSE)     printf("\x1b[%dm",A_REVERSE+20);
    }

    #define atrr_on(args) attron(args)
    #define atrr_off(args) attroff(args)

