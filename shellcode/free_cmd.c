#include "shell.h"

/**
 * free_cmd - free's cmd struct string
 * @cmd: pointer to struct
 */
void free_cmd(cmdstruct *cmd)
{
	free(cmd->must_free);
}
