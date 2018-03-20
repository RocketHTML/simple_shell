#ifndef SHELL
#define SHELL
#include "include_all.h"

typedef struct commandstruct {
	int argc;
	char **argv;
	char *must_free;
} cmdstruct;

typedef struct builtin {
	char *name;
	int (*f)(char **);
} builtin;

void eval(char *cmdline);
int parse(char *cmdline, cmdstruct *cmd);
int runAlias(cmdstruct *cmd, int bg);
int runUserExecutable(cmdstruct *cmd, int bg);
int runBuiltinFunction(cmdstruct *cmd, int bg);
void free_cmd(cmdstruct *cmd);
int moo(char **argv);
#endif
