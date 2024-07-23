/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:36:14 by iwaslet           #+#    #+#             */
/*   Updated: 2023/04/24 16:23:42 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_howmany(char const *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			n++;
		i++;
	}
	return (n);
}

static char	*ft_fill_word(char const *str, int start, char c)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (str[start + i] && str[start + i] != c)
	{
		len++;
		i++;
	}
	word = malloc (sizeof(char) * len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (str[start + i] && i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_free(char **tab, int j)
{
	while (--j >= 0)
		free(tab[j]);
	free(tab);
	return (NULL);
}

static char	**ft_fill_tab(char const *s, char c, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			tab[j] = ft_fill_word(s, i, c);
			if (tab[j] == NULL)
				return (ft_free(tab, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * ft_howmany(s, c));
	if (!tab)
		return (NULL);
	tab = ft_fill_tab(s, c, tab);
	return (tab);
}

/*int	main(void)
{
	char const	*s;
	char		c;
	char **str;

	s = "      split       this for   me  !       ";
	c = ' ';
	str = ft_split(s, c);
	while (*str != 0)
	{
		printf("|%s|\n", *str);
		str++;
	}
return (0);
}*/