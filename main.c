#include "shell.h"

/**
  * main - Entry point of the simple shell program.
  *
  * Return: Always returns EXIT_SUCCESS.
  */
int main(void)
{
	char *command;

	while (1)
	{
		display_prompt();
		command = read_command_line();
		if (command == NULL)
		{
			putchar('\n');
			break;
		}
		if (strlen(command) > 0)
		{
			execute_command(command);
		}
		free(command);
	}
	exit(EXIT_SUCCESS);
}
