#include <stdio.h>
#define LSH_RL_BUFSIZE 1024`
#define LSH_TOK_BUFSIZE 64

#define LSH_TOK_DELIM " \t\r\n\a"

char *builtCommands[] = {
    "cd",
    "help",
    "exit"
};


int (*builtFun[]) (char **) = {
    &ka_cd,
    &ka_help,
    &ka_exit
}

int sBuiltins() {
  return sizeof(builtCommands) / sizeof(char *);
}

// FUNCTIONS
int sCD(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }
  return 1;
}

int shelp(char **args)
{
  int i;
  printf("Stephen Brennan's LSH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < sBuiltins(); i++) {
    printf("  %s\n", builtCommands[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}

int sExit(char **args)
{
  return 0;
}


// END OF FUNCTIONS




int sLaunch(char **args){
    pid_t pid, wpid;
    int status;
  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
                perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("lsh");
  } else {
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

char sSplitLine(char *line) {
    int bufsize = LSH_TOK_BUFSIZE, pos = 0;
    char **tokens = malloc (buffsize * sizeof(char*));
    char *token;

    if(!tokens) {
            fprintf(stderr, "lsh: allocation error")
            exit(EXIT_FAILURE);
    }

    token = strtok(line, LSH_TOK_DELIM);
    while(token != NULL){
        tokensp[pos] = token;
        pos++;

        if(pos >= bufsize) {
            bufsize += LSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));

            if(!tokens) {
                fprintf(stderr, "lsh: allocation error \n");
                exit(EXIT_FAILURE);
            }
            token = strtok(NULL, LSH_TOK_DELIM);
        }
        tokens[pos] = NULL;
        return tokens;
    }
}

char *sReadLine(void) {
    int bufsize = LSH_RL_BUFSIZE;
    int pos = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if(!buffer) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c=getchar();

        if(c==EOF || c=='\n') {
            buffer[pos] = '\0';
            return buffer;
        } else {
        buffer[pos] = c;
        }pos++;

        if (pos >= bufsize) {
            bufsize+= LSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);

            if (!buffer) {
                bufsize += LSH_RL_BUFSIZE;
                buffer = realloc(buffer,bufsize);
                exit(EXIT_FAILURE);
            }
        }
    }
}

void sLoop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf(": ");
        line = sReadLine();
        args = sSplitLine(line);
        status = sExecute(args);

        free(line);
        free(args);
    }while(status)

}


int sExecute(char **args)
{
  int i;

  if (args[0] == NULL) {
    // An empty command was entered.
    return 1;
  }

  for (i = 0; i < sBuiltins(); i++) {
    if (strcmp(args[0], builtCommands[i]) == 0) {
      return (*builtFun[i])(args);
    }
  }

  return sLaunch(args);
}


int main(nt argc, char **argv)
{
    sLoop();
    return 0;
}
