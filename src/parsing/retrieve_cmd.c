#include "../../inc/minitry.h"

t_command   retrieve_cmd(char *input)
{
    t_array *tab;
    t_lexer	lexer;
    int		i;

    i= 0;
    tab = init_array();
    while (input[i])
    {
        if (isspace(input[i]) = 0)
            i++;
        else if (input[i] == '|')
            lexer->operator = PIPE; //indiquer sa position qq part ? 
		else if (input[i] == '<')
			lexer->operator = IN;
		else if (input[i] == '>')
			lexer->operator = OUT;
		else if (input[i] == '<<')
			lexer->operator = HEREDOC;
		else if (input[i] == '>>')
			lexer->operator = APPEND;
		else if (input[i] == '\"')
		{
			i++;
			while (input[i] != '\"')
			{
				if (input[i] == '\0')
					syntax error
				stocker chaque charctere
				i++;
			}
		}
		else if (input[i] == '\'')
		{
			i++;
			while (input[i] != '\'')
			{
				if (input[i] == '\0')
					syntax error
				stocker chaque charctere
				i++;
			}
		}
		i++;
    }
}

int init_array()
{

}