/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:07:41 by iwaslet           #+#    #+#             */
/*   Updated: 2023/04/17 15:01:30 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char const *set, char c)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

static int	ft_lengthi(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_isset(set, s1[i]))
		i++;
	return (i);
}

static int	ft_lengthl(char const *s1, char const *set)
{
	int	l;

	l = ft_strlen(s1) - 1;
	if (l < 0)
		l = 0;
	while (ft_isset(set, s1[l]))
		l--;
	return (l);
}

static int	ft_mallocsize(char const *s1, char const *set)
{
	int		i;
	int		l;
	int		f;

	l = ft_lengthl(s1, set);
	i = ft_lengthi(s1, set);
	if (i < l)
		f = l - i + 2;
	else
		f = 1;
	return (f);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		l;
	int		n;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == 0)
		return (ft_calloc(1, 1));
	l = ft_lengthl(s1, set);
	i = ft_lengthi(s1, set);
	n = 0;
	str = malloc(sizeof(char) * ft_mallocsize(s1, set));
	if (!str)
		return (NULL);
	while ((i + n) <= l)
	{
		str[n] = s1[i + n];
		n++;
	}
	str[n] = '\0';
	return (str);
}
