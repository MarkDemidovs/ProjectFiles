#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

char inputU[];
int quit = 0;

// COMMANDS
void help_CT() {
    printf(ANSI_COLOR_CYAN "Welcome to CTerminal! \n");
    printf("--- Commands ---\n");
}

///////////////



void foundError() {
    printf(ANSI_COLOR_YELLOW "'");
    printf("%s", inputU);
    printf("'");
    printf( " was found, but no further attributes were added. \n" ANSI_COLOR_RESET);
}

void error() {
    printf(ANSI_COLOR_RED "'");
    printf("%s", inputU);
    printf("'");
    printf( " was not recognized. Verify if spelling is correct.\n" ANSI_COLOR_RESET);
}

void clearInput(){
    inputU[0] = '0';
}

void checkCommand() {
    if(strcmp(inputU, "help") == 0) {
        foundError();

        clearInput();
    }

    if (inputU[strlen(inputU) - 1] == '\n')
        inputU[strlen(inputU) - 1] = '\0';

    if(strcmp(inputU, "help ct") == 0) {
        help_CT();
    }

}

void defaultLine() {
    printf(ANSI_COLOR_GREEN "CTerminal v1.0 Launched!\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_GREEN "Use 'help ct' to get a list of commands.\n"    ANSI_COLOR_RESET );
}

void ask() {
    while (quit==0) {
        clearInput();
        printf(": ");
        scanf("%s", inputU);

        checkCommand();
    }
}

int main()
{
    defaultLine();
    ask();

    return 0;
}
