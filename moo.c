#include "shell.h"
/**
 * moo - prints cow
 * @argv: inputs
 * Return: 0
 */
int moo(cmdstruct *cmd)
{
	int i;
	char **argv = cmd->argv;

	printf("< moOh >\n");
	for (i = 1; argv[i]; i++)
		if (i == 1)
			printf("/ %s \\\n", argv[i]);
		else if (argv[i + 1] == NULL)
			printf("\\ %s /\n", argv[i]);
		else
			printf("| %s |\n", argv[i]);
	printf("  \\ ^__^\n");
	printf("    (oo)\\_______\n");
	printf("    (__)\\       )\\/\\\n");
	printf("        ||----w |\n");
	printf("        ||     ||\n");
	return (0);
}
