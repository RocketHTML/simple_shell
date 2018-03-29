#include "shell.h"

/**
 * env - This gets and prints the environmental variable.
 * @cmd: This is our pointer holding our command.
 *
 * Return: 0.
 */

int env(cmdstruct *cmd)
{
	int i;

	for (i = 0; cmd->env[i]; i++)
		printf("%s\n", cmd->env[i]);
	return (0);
}
