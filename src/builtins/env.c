/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:03:21 by csteylae          #+#    #+#             */
/*   Updated: 2024/09/04 15:10:35 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

void	exec_env(t_shell *shell)
{
	int	i;

	i = 0;
	if (!shell->env && !shell->env[0])
		return ;
	while (shell->env[i])
	{
		ft_printf("%s\n", shell->env[i]);
		i++;
	}
}
