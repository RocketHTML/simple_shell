#include "shell.h"

/**
 * eval - evaluate command
 * @cmdline: command to evaluate
 */
void eval(char *cmdline)
{
	int bg;
	cmdstruct cmd;

	printf("Evaluating '%s'\n", cmdline);
	bg = parse(cmdline, &cmd);

	// parse error
	if (bg == -1)
	{
		printf("parse error\n");
		free_cmd(&cmd);
		return;
	}
	// empty line - ignore
	if (cmd.argv[0] == NULL)
	{
		free_cmd(&cmd);
		return;
	}

	if (runAlias(&cmd, bg) == -1)
		if (runUserExecutable(&cmd, bg) == -1)
			if (runBuiltinFunction(&cmd, bg) == -1)
				printf("%s NOT FOUND\n", cmd.argv[0]);
	free_cmd(&cmd);
}
