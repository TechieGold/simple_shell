#include "shell.h"

/**
  * print_environment - Function to print the current environment.
  *
  * Return: void.
  */
void print_environment(void)
{
	extern char **environ;
	char **env = environ;
	size_t len;
	while(*env != NULL)
	{
		len = strlen(*env);
		write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}

/**
  * handle_exit_command - Handles exit command with or without argument.
  * @user_input: The user's input command.
  *
  * Return: Returns 1 to exit the shell or the specified status to exit the shell.
  */
int handle_exit_command(char *user_input, int *exit_status)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[MAX_ARGS];

	parse_command(user_input, command, args);

	if (strcmp(command, "exit") == 0)
	{
		if (args[1] != NULL)
		{
			*exit_status = atoi(args[1]);
		}

		return (1);
	}

	return (0);
}
