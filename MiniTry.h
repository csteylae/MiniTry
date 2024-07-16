#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_redirect
{
    //?
}   t_redirect;

typedef struct s_command
{
    char        **cmd;
    int         index;
    int         flag; //quel type ?
    t_redirect  redirect; //?
    char        **open;
    char        **read;
}   t_command;

typedef struct s_data
{
    char         **envp;
    t_command    *tab;
}   t_data;
