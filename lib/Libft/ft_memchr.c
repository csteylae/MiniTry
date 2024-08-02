/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:56:35 by iwaslet           #+#    #+#             */
/*   Updated: 2023/04/14 16:08:29 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*r;

	r = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (r[i] == ((unsigned char) c))
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
