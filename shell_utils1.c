#include "shell.h"

/**
* display_prompt - function to display the shell prompt
*
* Return: void
*/
void display_prompt(void)
{
	const char *prompt = "shell$ ";
	size_t prompt_len = strlen(prompt);
	size_t i;

	for (i = 0; i < prompt_len; i++)
	{
		_putchar(prompt[i]);
	}

	fflush(stdout);
}

/**
  * read_command - Function to read the user command from stdin.
  *
  * Return: A pointer to the user input string or NULL on EOF.
  */
char *read_command()
{
	char *command_input = NULL;
	size_t bufsize = 0;
	int characters_read;

	display_prompt();

	characters_read = getline(&command_input, &bufsize, stdin);

	if (characters_read == -1)
	{
		free(command_input);
		return (NULL);
	}
	command_input[strcspn(command_input, "\n")] = '\0';

	return (command_input);
}


/**
  * parse_command - function to parse the command and its arguments.
  * @user_input: The user input string.
  * @command: Buffer to store the command.
  * @args: Array to store the command's arguments.
  *
  * Return: void.
  */
void parse_command(char *user_input, char *command, char *args[])
{
	char *temp_input = strdup(user_input);
	char *token;
	int i = 0;

	token = strtok(temp_input, " \n");
	if (token == NULL)
	{
		command[0] = '\0';
		args[0] = NULL;
		free(temp_input);
		return;
	}
	strcpy(command, token);

	while (token != NULL)
	{
		args[i] = strdup(token);
		if (args[i] == NULL)
		{
			perror("Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;

	free(temp_input);

}
