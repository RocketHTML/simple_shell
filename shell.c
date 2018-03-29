#include "shell.h"
/**
 * main - program start
 * @argc: number of arguments
 * @argv: arguments
 * @env: This is our environment.
 *
 * Return: returns 0 on success
 */
int main(int argc, char **argv, char **env)
{
	size_t init_size = 1024;
	char *cmdline;
	char prompt[] = "$ ";

	cmdline = malloc(sizeof(char) * init_size);

	while (1)
	{
		printf("%s", prompt);

		if (getline(&cmdline, &init_size, stdin) == -1)
			if (ferror(stdin))
				error("getline error");
			else
			{
				printf("\n");
				exit(0);
			}
		/* remove trailing newline*/
		cmdline[strlen(cmdline) - 1] = '\0';

		/* evaluate command line*/
		eval(cmdline, env);
	}
}
