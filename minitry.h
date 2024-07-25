#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_redirect
{
    char    **open;
    char    **read;
}   t_redirect;

typedef struct s_command
{
    char        *cmd;
    t_redirect  redirect;
}   t_command;

typedef struct s_data
{
    char        **envp;
    t_command   *tab;
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