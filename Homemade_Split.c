/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Homemade_Split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:48:46 by iwaslet           #+#    #+#             */
/*   Updated: 2024/07/16 17:58:09 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//liste des separateurs: < 60, > 62, | 124,  32, >> append, << here-doc et les separateurs ou faut gerer les espaces: " 34, ' 39

int pars_it(char *input)
{
    if (check_syntax(input) != 0)
        return (error_fct());
    ft_strtrim(input, ' ');
    return (0);
}

char    **My_Split(char *input)
{
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
