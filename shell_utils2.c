#include "shell/h"

/**
  * find_executable_path - Function to find the full path of the executable.
  * @command: The command to be executed.
  *
  * Return: A pointer to the full path if found, NULL if not found.
  */
char *find_executable_path(const char *command)
{
	char *path_env = getenv("PATH");
	CHAT *path_copy = NULL;
	char *full_path = NULL;
	const char *delim = ":";
	int access_result;
	char *token;

	if (path_env == NULL || command == NULL)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(path_copy, delim);

	while (token != NULL)
	{
		path_len = strlen(token);
		command_len = strlen(command);

		full_path = (char *) malloc(path_len + command_len + 2);

		if (!full_path)
		{
			perror("Memory allocation error");
			exit (EXIT_FAILURE);
		}

		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, command);

		access_result = access(full_path, X_OK);

		if (access_result == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		full_path = NULL;

		token = strtok(NULL, delim);
	}
	free(path_copy);
	return (NULL);
}


/**
  * execute_command - Function to execute the command.
  * @command: The command to be executed.
  * @args: Array of argument for the command.
  *
  * Return: void.
  */
void execute_command(const char *command, char *const args[])
{
	pid_t pid;

	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(command, args, NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}


/**
  * free_args - Function to free memory allocated for the arguments.
  * @args: Array of arguments to be freed.
  *
  * Return: void.
  */
void free_args(char *args[])
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
}
