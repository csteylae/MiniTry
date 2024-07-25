#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

/**
 * A structure containing the potential files for write and read redirection
 *
 * - redirect->read	contains potential input redirections caused by the operator < filename 
 * - redirect->write	contains potential output redirections caused by the operator > filename
 *
 * Each  member is optional 
 */
typedef struct s_redirect
{
    char        **read;
    char        **write;
}   t_redirect;

/**
 * A structure containing the commands that will by passed to the executor in form of an array of t_command
 *
 * - command->cmd		contains in cmd[0] command name and the rest of the array contains its potential attribute
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

typedef enum
{
    PIPE,
    S_QUOTE,
    D_QUOTE,
    WORD,
    HEREDOC,
    APPEND
}	token_type;

typedef struct s_token
{

}   t_token;
