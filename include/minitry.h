#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

/**
 * A structure containing all the potential necessary informations about a redirction
 *
 * - redirect->input	contains potential input redirection(s) caused by the operator < filename 
 * - redirect->output	contains potential output redirection(s) caused by the operator > filename
 * - redirect->fd_in	is an array of struct fd 
 * This struct and all members are optional 
 */
typedef struct s_redirect 
{
	int	fildes;
	char *filename;
	redirection_type;
	
}   t_redirect;

/**
 * A structure containing the commands that will by passed to the executor in form of an array of t_command
 *
 * - command->cmd		contains in cmd[0] command name and the rest of the array contains its potential options
 * - command->redirect	contains the potential redirections of the command. It is an array of redirection struct. It is an optional member (can be set to NULL) (?)
 */
typedef struct s_command
{
    char        **cmd;
    t_redirect  *redirect;
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

typedef enum e_redirection_type {
    REDIR_IN,   // <
    REDIR_OUT,  // >
    REDIR_APP,  // >>
    REDIR_HEREDOC // <<
} t_redirection_type;

