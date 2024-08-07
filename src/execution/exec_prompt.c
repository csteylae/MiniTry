/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:07:13 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/07 12:07:24 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

int	exec_prompt(t_data *data)
{
	int	i;
	int	*pid;
//	int	pipe_fd[2];

	i = 0;
	pid = malloc(sizeof(*pid) * data->tab_size);
	if (!pid)
		return (EXIT_FAILURE);
	while (i != data->tab_size)
	{
//		pipe(pipe_fd);
		pid[i] = fork();
		if (pid[i] == 0)
			exec_command(data, i);
		i++;
	}
	while (i != 0)
	{
		wait(NULL);
		i--;
	}
	free(pid);
	free_tab_cmd(data->tab_size, data->tab);
	return (0);
}
