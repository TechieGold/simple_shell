#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64
#define MAX_COMMAND_LENGTH 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int _putchar(char c);
void display_prompt();
char *read_command();
void parse_command(char *user_input, char *command, char *args[]);
void execute_command(const char *command, char *const args[]);
char *find_executable_path(const char *command);
void free_args(char *const args[]);
void print_environment(void);
#endif /* SHELL_H */
