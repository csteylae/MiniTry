/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Homemade_Split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:48:46 by iwaslet           #+#    #+#             */
/*   Updated: 2024/07/15 14:58:01 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//liste des separateurs: < 60, > 62, | 124,  32, >> ? et les separateurs ou faut gerer les espaces: " 34, ' 39

int pars_it(char *input)
{
    ft_strtrim(input, ' ');
    if (check_open_quotes(input, 'a') || check_open_quotes(input, 'b'))
        return (error_fct(input));
    return (0);
}

char    **My_Split(char *input)
{
    //passer une premiere fois sur la string pour verifier qu'il n'y a pas de quotes ouvertes (2x pour " et ' avec une seule fct)
    //trouver tous les whitespace puis les separateurs
    //tout separer en "blocs" (tab)
    //parcourir la liste/tab et reseparer aux pipes
}
/* FONCTIONS NECESSSAIRES
- str_cmp
- allouer memoire struct
- strtrim pour enlever les espaces inutiles autour
- split
- strlen
- strtrim ?
- isspace (personalise mdr)
- pleins de free et de mallocs sa mere
*/

int check_open_quotes(char *str, char c)
{
    while (str)
    {
        if (str = c)
        {
            while (str++ != '\0')
            {
                if (str = c)
                    return (0);
            }
            return (1);
        }
        str++;
    }
    return (0);
}

int error_fct(char *input)
{
    
}

char	**create_tab(int nbr)
{
	int 	size;
    char    **tab;

	size = nbr + 1;
    tab = malloc(sizeof(char) * size); //type sera pas forcement char
    return (tab);
}

int is_separator(char *str)
{
	
}

void    save_space(char *str, char c)
{
    while (str)
    {
        if (str = c)
        {
            str++;
            while (str != c)
            {
                if (str = 32)
                    str = -32;
                str++;
            }
        }
        str++;
    }
}