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
