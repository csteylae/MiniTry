#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

/**
 * A structure containing the potential files for write and read redirection
 *
 * - redirect->input	contains potential input redirection(s) caused by the operator < filename 
 * - redirect->output	contains potential output redirection(s) caused by the operator > filename
 *
 * Each  member is optional 
 */
typedef struct s_redirect
{
    char        **input;
    char        **output;
}   t_redirect;

/**
 * A structure containing the commands that will by passed to the executor in form of an array of t_command
 *
 * - command->cmd		contains in cmd[0] command name and the rest of the array contains its potential options
 * - command->redirect	contains the potential redirections of the command. It is an optionnal member (can be set to NULL) (?)
 */
typedef struct s_command
{
    char        **cmd;
    t_redirect  redirect;
}   t_command;

/**
 *	A big structure that will contains all important information to parse from parsing to execution. 
 *
 *	data->envp	contains the envp variable
 *	data->tab	contains the array of commands parsed from readline()
 */
typedef struct s_data
{
    char         **envp;
    t_command    *tab;
}   t_data;

enum e_tokens {
    PIPE,
    QUOTE,
    D_QUOTE,
    WORD
}	t_tokens;
