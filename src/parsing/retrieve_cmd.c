#include "../../inc/minitry.h"

t_command   retrieve_cmd(char *input)
{
    t_darray *tab;
    t_lexer	lexer;
    int		i;
	int		j;

    i = 0;
	j = 0;
    tab = init_array(1, );
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

t_darray *init_array(int amount, size_t type_size)
{
	t_darray	darray;

	// darray = malloc(sizeof(t_darray));
	// if (!darray)
	// 	return ((void*)NULL);
	darray.type_size = type_size;
	darray.block = type_size;
	darray.size = amount;
	darray.max_size = type_size * darray.size;
	darray.content = malloc(sizeof(t_lexer)*amount); //initier un lexer par bloc ?
	if (!darray.content)
		return ((void*)NULL);
	return (&darray);
}

int	append_array(t_darray darray)
{

}

void	free_temp_array(t_darray darray)
{
	free(darray.content);
}

int	realloc_array(t_darray darray)
{

}

int	at_index(t_darray darray)
{

}
