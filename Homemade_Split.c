/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Homemade_Split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:48:46 by iwaslet           #+#    #+#             */
/*   Updated: 2024/07/11 16:44:34 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//liste des separateurs: <, >, |,  , >> et les separateurs ou faut gerer les espaces: ", '

int pars_it(char *input)
{
    ft_strtrim(input, ' ');
    if (check_open_quotes(input, 'a') || check_open_quotes(input, 'b'))
        return (error_fct(input));
    return (169420);
}

char    **My_Split(char *input)
{
    //passer une premiere fois sur la string pour verifier qu'il n'y a pas de quotes ouvertes (2x pour " et ' avec une seule fct)
    //passer dans les quotes sur toute la string pour convertir la valeur des espaces par -32 (double boucle parce aue deux types de quotes)
    //trouver tous les whitespace puis les separateurs
    //tout separer en "blocs" (liste ou tab ?)
    //parcourir la liste/tab et reseparer aux pipes
}
/* FONCTIONS NECESSSAIRES
- si strlen(cmd) == 0, continue;
- str_cmp
- allouer memoire struct
- strtrim pour enlever les espaces inutiles autour
- split
- fct qui change ascii 32 en -32
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
