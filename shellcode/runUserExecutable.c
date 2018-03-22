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
	pathnode *pathhead;
	char *commandpath;

	pathhead = make_pathlist(); 			//free path list
	commandpath = pathsearch(cmd->argv[0], pathhead); 	//free commandpath

	if (commandpath)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("runUserExecutable: could not make child process");
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(commandpath, cmd->argv, NULL) == -1)
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
		return (-1); //free path list
	return (0);
}
