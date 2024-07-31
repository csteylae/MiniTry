#include "../Libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

/**
 * An enum to identify the different type of operator, including  redirection that can affect a command
 *
 * REDIR_IN :	<
 * REDIR_OUT:	>	
 * REDIR_HEREDOC : <<
 * REDIR_APPEND :	>>
 */
enum e_tokens {
    PIPE,
    QUOTE,
    D_QUOTE,
    WORD,
    REDIR_IN, 
    REDIR_OUT,
    REDIR_APP,
    REDIR_HEREDOC
}	t_tokens;

/**
 * A structure containing all the potential necessary informations about a redirction
 *
 * int fildes :	the optionnal file descriptor that can be associated to a redirection (such as "fd< filename")
 * char *filename : the name of the file in which the command is redirected to read from or to write to
 * type	: the kind of redirection
 *
 *  This struct and all its members are optional 
 */
typedef struct s_redirect 
{
	int					fd;
	char				*filename;
	e_tokens			type;
	
}   t_redirect;

/**
 * A structure containing the commands that will by passed to the executor in form of an array of t_command
 *
 * - command->cmd		contains in cmd[0] command name and the rest of the array contains its potential options
 * - command->redirect	contains all the potential redirections that affect the command. It is an array of redirection. It is an optional member (can be set to NULL) (?)
 */
typedef struct s_command
{
    char        **cmd;
    t_redirect  *in;
    t_redirect  *out;
    t_redirect  *heredoc;
    t_redirect  *append;
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
    struct t_command    *tab;
}   t_data;

typedef struct s_array
{
    void    *content;
    size_t  max_size;
    size_t  type_size;
    size_t  size;
    size_t  nbr;
    size_t  block;
}       t_array

void	exec_cd(char *cmd);
void	exec_env(char *str, char **envp);
