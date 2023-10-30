#ifndef multiCompat_h
#define multiCompat_h

#ifdef __cplusplus
extern "C" {
#endif

/*Will implent all functions when finished*/
#include "stdlibCompat.h"
#include "ncursesCompat.h"
#include "ansiCompat.h"
#include "Play_Sound.h"


#include <string.h>//strcmp(), strncmp()
#define system(cmd) do { \
    if(strcmp(cmd,"pause")==0 || strcmp(cmd,"PAUSE")==0){sysPause();}\
    else if(strcmp(cmd,"cls")==0 || strcmp(cmd,"CLS")==0){sysClear();}\
    else if (strncmp(cmd, "color", 5) == 0 || strncmp(cmd, "COLOR", 5) == 0) {\
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
        }else{/*default system call could be improved using PWSH insted of defualt CMD shell */\
        system(cmd);}\
    } \
} while (0)

/*
            char powershell_command[512]; \
            snprintf(powershell_command, sizeof(powershell_command), "pwsh -c \"%s\"", cmd); \
            system(powershell_command); \
*/


#ifdef __cplusplus
}
#endif//__cplusplus

#endif//multiCompat_h
