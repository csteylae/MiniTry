#include "../../inc/minitry.h"

t_command   retrieve_cmd(char *input)
{
    t_darray *tab;
    t_lexer	lexer;
    int		i;
	int		j;

    i = 0;
	j = 0;
    tab = init_array();
	if (!tab)
		return ((void)NULL);
    while (input[i]) //identifier aussi les WORDS
    {
        if (ft_isspace(input[i]) = 0)
            i++;
        else if (input[i] == '|')
            tab[j].word = '|' // can't malloc the string because I dunno how long
			tab[j].type = PIPE
			lexer->operator = PIPE; //indiquer sa position qq part ? 
		else if (input[i] == '<<') //utils str_cmp
			lexer->operator = REDIR_HEREDOC;
		else if (input[i] == '>>')
			lexer->operator = REDIR_APP;
		else if (input[i] == '<')
			lexer->operator = REDIR_IN;
		else if (input[i] == '>')
			lexer->operator = REDIR_OUT;
		else if (input[i] == '\"')
		{
			while (input[i] != '\"') //ici on doit conserver les variables d'env uniquement
			{
				if (input[i] == '\0')
					error_fct();
				stocker chaque carctere dans une string //puis transferer cette strinf dans tab et puis la free ou direct dans tab ?
				i++;
			}
		}
		else if (input[i] == '\'')
		{
			lexer->operator = QUOTE;
			i++;
			while (input[i] != '\'') //ici on gere rien du tout c'est un WORD, \n, \t, \v, \f, \r
			{
				if (input[i] == '\0')
					error_fct();
				stocker chaque carctere dans une string
				i++;
			}
		}
		i++;
    }
}

t_darray *init_array()
{
	t_darray	darray;

	darray.content = malloc(sizeof(t_lexer));
	if (!darray.content)
		return ((void*)NULL);
	return (&darray);
}

int	append_array()
{

}

int	free_temp_array()
{

}

int	realloc_array()
{

}

int	at_index()
{

}
