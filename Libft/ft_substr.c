/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:48:33 by iwaslet           #+#    #+#             */
/*   Updated: 2023/04/15 19:32:48 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	size;
	size_t			i;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (size < start)
		start = size;
	i = 0;
	while (s[start + i] && i < len)
		i++;
	sub = malloc (sizeof(char) * (i + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], i + 1);
	return (sub);
}
