/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:49:38 by iwaslet           #+#    #+#             */
/*   Updated: 2023/10/17 15:20:33 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		lentot;

	if (!s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	i = -1;
	j = 0;
	lentot = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (lentot + 1));
	if (!str)
		return (NULL);
	while (++i < ft_strlen(s1))
		str[i] = s1[i];
	while ((i + j) < (lentot))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
