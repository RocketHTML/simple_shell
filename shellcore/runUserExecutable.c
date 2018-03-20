#include "shell.h"
/**
 * runUserExecutable - run's system command
 * @cmd: pointer to command struct
 * @bg: if should run in background or not
 * Return: -1 on failure, 0 on success
 */
int runUserExecutable(cmdstruct *cmd, int bg)
{
	struct stat st;
	pid_t child_pid;
	int status = 0;
	//char *path;
	//char *command_path;

	if (stat(cmd->argv[0], &st) == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("runUserExecutable: could not make child process");
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(cmd->argv[0], cmd->argv, NULL) == -1)
			{
				perror("runUserExecutable: could not execute file");
				return (-1);
			}
		}
		else if (!bg)
			wait(&status); // thats how you get the status
		else
			printf("Child in background [%d]\n", child_pid);

		return (status);
	}
	else
		return (-1);
	return (0);
}
