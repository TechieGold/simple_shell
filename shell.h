#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void display_prompt();
char *read_command_line();
void tokenize_command(char *command, char *args[]);
void execute_command(char *command);

#endif /* SHELL_H */
