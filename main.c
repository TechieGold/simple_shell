#include "shell.h"

/**
  * main - Entry point of the simple shell program.
  *
  * Return: Always returns EXIT_SUCCESS.
  */
int main(void)
{
	char *user_input;
	char command[MAX_CMD_LENGTH];
	char *args[MAX_ARGS];
	char *executable_path;

	while (1)
	{
		user_input = read_command();

		if (user_input == NULL)
		{
			_putchar('\n');
			break;
		}

		parse_command(user_input, command, args);

		if (strcmp(command, "exit") == 0)
		{
			free(user_input);
			break;
		}
		
		if (strstr(command, '/') != NULL)
		{
			executable_path = strdup(command);

			if (executable_path == NULL)
			{

				printf("command not found: %s/n", command);
				free(user_input);
				free_args(args);
				continue;
			}
		}

		execute_command(executable_path, args);
		free(executable_path);
		executable_path = NULL;

		free(user_input);
		free_args(args);
	}
	return (0);
}
