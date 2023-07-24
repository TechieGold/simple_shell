#include "shell.h"

/**
  * main - Entry point of the simple shell program.
  *
  * Return: Always returns EXIT_SUCCESS.
  */
int main(void)
{
	char *user_input;
	char command[MAX_COMMAND_LENGTH];
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
		else if (strcmp(command, "env") == 0)
		{
			print_environment();

		}
		else if (strchr(command, '/') != NULL)

		{
			executable_path = strdup(command);

			if (executable_path == NULL)
			{

				perror("Memory allocation failed");
				free(user_input);
				free_args(args);
				continue;
			}
		}

		else
		{
			executable_path = find_executable_path(command);

			if (executable_path == NULL)
			{
				perror("lsh: command not found");
				free(user_input);
				free_args(args);
				continue;
			}
		}
		args[MAX_ARGS- 1] = NULL;

		execute_command(executable_path, args);
		executable_path = NULL;

		free(user_input);
		free_args(args);

	}
	return (0);

}
