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
		{NULL, NULL}
	};
	return (-1);
}
