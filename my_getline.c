#include "shell.h"

/**
  * my_getline - Custom implementation of getline.
  *
  * Return: A pointer to the user input string or NULL if EOF.
  */
char *my_getline(void)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_pos = 0;
	static ssize_t bytes_read = 0;
	char *user_input, *temp;
	size_t input_size = 0;

	while (1)
	{
		if (buffer_pos >= bytes_read)
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytes_read == 0)
			{
				if (input_size == 0)
				
					return (NULL);
				break;
			}
			buffer_pos = 0;
		}

		if (buffer[buffer_pos] == '\n')
		{
			buffer_pos++;
			break;
		}

		if (input_size == 0)
		{
			user_input = malloc(sizeof(char) * (BUFFER_SIZE + 1));
			if (!user_input)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}

		}

		else if (input_size % BUFFER_SIZE == 0)
		{
			temp = realloc(user_input, sizeof(char) * (input_size + BUFFER_SIZE + 1));
			if (!temp)
			{
				free(user_input);
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
			user_input = temp;
		}

		user_input[input_size] = buffer[buffer_pos];
		input_size++;
		buffer_pos;
	}

	if (!user_input)
	{
		user_input[input_size] = '\0';
	}

	return (user_input);
}
