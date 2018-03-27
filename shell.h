#ifndef SHELL
#define SHELL
#include "include_all.h"

typedef struct commandstruct {
	int argc;
	char **argv;
	char *must_free;
	char **env;
} cmdstruct;

typedef struct builtin {
	char *name;
	int (*f)(cmdstruct *);
} builtin;

typedef struct pathnode {
	char *path;
	struct pathnode *next;
} pathnode;

void eval(char *cmdline, char **env);
int parse(char *cmdline, cmdstruct *cmd, char **env);
int runAlias(cmdstruct *cmd, int bg);
int runUserExecutable(cmdstruct *cmd, int bg);
int runBuiltinFunction(cmdstruct *cmd, int bg);
void free_cmd(cmdstruct *cmd);
int moo(cmdstruct *cmd);
int env(cmdstruct *cmd);
int exit2(cmdstruct *cmd);
pathnode *make_pathlist();
char *pathsearch(char *command, pathnode *head);
#endif
