/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:23:29 by csteylae          #+#    #+#             */
/*   Updated: 2024/07/31 11:40:56 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h" 

int	ft_strnlen(char *str, char c)
{
	int	i = 0;
	while (str[i] != c)
		i++;
	return i;
}
void	exec_cd(char *input)
{
	char **cmd = ft_split(input, ' ');
	
	if (!ft_strncmp("cd", cmd[0], ft_strlen("cd")))
	{
		printf("LOL\n");
		if (cmd[1])
			chdir(cmd[1]);
	}
}
