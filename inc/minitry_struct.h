/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitry_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:20:42 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/01 14:19:01 by iwaslet          ###   ########.fr       */
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
}

typedef struct s_lexer
{
    char    *word;
    int     operator;
}   t_lexer;

/**
 * A structure containing all the potential necessary informations about a redirction
 *
 * int fd (optionnal):				The file descriptor that can be associated to a redirection (such as "fd< filename")
 * char *filename :					The name of the file that redirects the input or output stream to read from or write to.
 * heredoc_delimiter (optionnal) :	Only for the case of REDIR_HEREDOC (noted "<< name of delimiter"). In all other case it will be set to NULL.
 *
 *  This struct and all its members are optional 
 */
typedef struct s_redirect 
{
	int					fd;
	char				*filename;
	char				*heredoc_delimiter;
}   t_redirect;

/**
 * A structure containing the commands that will by passed to the executor in form of an array of t_command
 *
 * - command->cmd	: 				it is an array of strings, as char **argv. It	contains in cmd[0] the command name and the others indexes contains its potential options
 * - command->in (optionnal)	: 	an array of struct t_redirect. Contains all the possible IN_REDIR (noted <) that can affect a command
 * - command->out (optionnal)	:	an array of struct t_redirect. Contains all the possible OUT_REDIR (noted >) that can affect a cmd
 * - command->heredoc (optionnal) : an array of struct t_redirect. Contains all the possible HEREDOC_REDIR (noted << delimitor_name). In that case, the redirect->heredoc_delimiter is not NULL and indicate the name of the delimiter.
 * - command->append (optionnal) :	an array of struct t_redirect. Contains all the possible APPEND_REDIR (noted >>).
 *
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
    char         **env;
    t_command    *tab;
}   t_data;

typedef struct s_array
{
    void    *content;
    size_t  max_size;
    size_t  type_size;
    size_t  size;
    size_t  nbr;
    size_t  block;
}       t_array;

# endif
