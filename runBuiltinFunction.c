#include "shell.h"
/**
 * runBuiltinFunction - run's builtin function
 * @cmd: pointer to command struct
 * @bg: if should run in background or not
 * Return: -1 on failure, 0 on success
 */
int runBuiltinFunction(cmdstruct *cmd, int bg)
{
	builtin functions[] = {
		{"moo", moo},
		{"env", env},
		{"exit", exit2},
		{NULL, NULL}
	};
	int i = 0;

	while (functions[i].name)
	{
		if (strcmp(cmd->argv[0], functions[i].name) == 0)
		{
			functions[i].f(cmd);
			return (0);
		}
		i++;
	}
	return (-1);
}
