#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_command
{
    char    **cmd;
    int     flag; //quel type ?
}   t_command;

typedef struct s_data
{
    char    **envp;
    char    **tab; //tableau de struct pas char *
}   t_data;
