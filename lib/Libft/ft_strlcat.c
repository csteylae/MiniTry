/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:08:30 by iwaslet           #+#    #+#             */
/*   Updated: 2023/04/19 17:11:15 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i])
		i++;
	if (dstsize > 0)
	{
		while (src[j] && i + j < dstsize - 1)
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	if (dstsize > i)
		dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
