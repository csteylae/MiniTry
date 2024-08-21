/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitry_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:20:42 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/20 16:16:23 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MINITRY_STRUCT_H

# define MINITRY_STRUCT_H

#include "minitry_lib.h"

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
};

typedef struct s_lexer
{
    char    *word;
    int     operator;
	enum e_tokens	type;
}   t_lexer;

/**
 * A structure containing all the potential necessary informations about a redirction
 *
 * int fd (optionnal):				The file descriptor that can be associated to a redirection (such as "fd< filename")
 * char *filename :					The name of the file that redirects the input or output stream to read from or write to.
 * heredoc_delimiter (optionnal) :	Only for the case of REDIR_HEREDOC (noted "<< name_of_delimiter"). In all other case it will be set to NULL.
 *
 *  This struct and all its members are optional 
 */
typedef struct s_redirect 
{
	int					fd;
	char				*filename;
	char				*hd_delimiter;
}   t_redirect;

/**
 * A structure containing the commands that will be passed to the execution
 * in form of an array of t_command
 *
 * - command->cmd	: 				an array of strings, as char **argv. Contains in cmd[0] the command name and the others indexes contains its potential options
 * - command->in (optionnal)	: 	an array of struct t_redirect. Contains all the possible IN_REDIR (noted <) that can affect a command
 * - command->out (optionnal)	:	an array of struct t_redirect. Contains all the possible OUT_REDIR (noted >) that can affect a cmd
 * - command->heredoc (optionnal) : an array of struct t_redirect. Contains all the possible HEREDOC_REDIR (noted << delimitor_name). In that case, the redirect->heredoc_delimiter is not NULL and indicate the name of the delimiter.
 * - command->append (optionnal) :	an array of struct t_redirect. Contains all the possible APPEND_REDIR (noted >>).
 */
typedef struct s_command
{
	char		**cmd;
	t_redirect	*in;
	t_redirect	*out;
	t_redirect	*heredoc;
	t_redirect	*append;
}	t_command;

/**
 *	A big structure that will contains all important information
 *
 *	shell.envp	contains the envp variable
 *	shell.tab	contains the array of commands parsed from readline()
 *	shell.tab_size 	the size of the array. Is the nb of commands passed
 *	shell.error	an int to indicate if an error occurs, 
 *		idk if we will keep it (just use in init_shell() in src/parsing/minitry.c
 */
typedef struct s_shell
{
	char		**env;
	t_command	*tab;
	int			tab_size;
	int			error;
}	t_shell;

typedef struct s_darray
{
	void	*content;
	size_t	max_size;
	size_t	type_size;
	size_t	size;
	size_t	nbr;
	size_t	block;
}	t_darray;

#endif
