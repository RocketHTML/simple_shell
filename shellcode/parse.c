#include "shell.h"
/**
 * count_words - counts words
 * @s: string
 * @delims: delimeters
 * Return: number of words
 */
int count_words(char *s, char *delims)
{
	int oldchar = 0;
	int is_delim = 0;
	int words = 0;
	int d;

	while (*s)
	{
		is_delim = 0;
		for (d = 0; delims[d]; d++)
			if (*s == delims[d])
				is_delim = 1;

		if (!oldchar && !is_delim)
			words++;

		if(is_delim)
			oldchar = 0;
		else
			oldchar = 1;

		s++;
	}
	return (words);
}
/**
 * parse - parses command line
 * @cmdline: command string to parse
 * @cmd: command struct to initialize
 * @env: environment
 * Return: 1 if command should run in background, -1 on error
 */
int parse(char *cmdline, cmdstruct *cmd, char **env)
{
	char delims[] = " \t\r\n";
	size_t cmdsize = strlen(cmdline);	
	int is_bg = 0, argc, i;
	char **argv;
	char *dup;

	if (cmdline == NULL)
		error("command line is NULL");

	argc = count_words(cmdline, delims);
	argv = malloc(sizeof(char *) * (argc + 1));
	if (!argv)
		return (-1);
	cmd->argc = argc;
	cmd->argv = argv;
	cmd->env = env;

	//how to free dup later - put it in command struct
	dup = strdup(cmdline);
	cmd->must_free = dup;

	cmd->argv[0] = strtok(dup, delims);
	for (i = 1; i < cmd->argc; i++)
	{
		cmd->argv[i] = strtok(NULL, delims);
	}
	cmd->argv[argc] = NULL;

	// ignore blank line
	if (cmd->argc == 0)
		return (1);

	// should job run in the background?
	if ((is_bg = (cmd->argv[argc - 1][0] == '&')) != 0)
		cmd->argv[--cmd->argc] = NULL;

	return (is_bg);
}
