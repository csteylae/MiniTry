/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:28:36 by iwaslet           #+#    #+#             */
/*   Updated: 2023/04/17 17:09:06 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	range;

	range = size * count;
	if (size && (count != range / size))
		return (NULL);
	str = malloc (size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
