/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:59:31 by iwaslet           #+#    #+#             */
/*   Updated: 2023/04/18 17:10:05 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenght(int n)
{
	int		len;
	long	nb;

	len = 1;
	nb = n;
	if (n < 0)
	{
		len = 2;
		nb = -nb;
	}
	while (nb >= 10)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static void	ft_swap(char *str, int size)
{
	char	c;
	int		i;

	i = 0;
	while (i < size)
	{
		c = str[i];
		str[i] = str[size - 1];
		str[size - 1] = c;
		i++;
		size--;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	long	nb;
	char	*str;

	i = 0;
	len = ft_lenght(n);
	nb = n;
	str = malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		nb = -nb;
	while (i < len - (n < 0))
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	if (n < 0)
		str[i] = '-';
	ft_swap(str, len);
	return (str);
}
