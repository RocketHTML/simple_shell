#include "shell.h"

int env(cmdstruct *cmd)
{
	int i;

	for (i = 0; cmd->env[i]; i++)
		printf("%s\n", cmd->env[i]);
	return (0);
}
