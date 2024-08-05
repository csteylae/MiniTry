/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:07:13 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/01 18:24:42 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

int	exec_prompt(t_data *data)
{
	int	i;
	int	*pid;
	int	pipe_fd[2];

	i = 0;
	pid = malloc(sizeof(*pid) * data->tab_size);
	if (!pid)
		return (EXIT_FAILURE);
	while (i != data->tab_size) //while we are not at the end of the prompt
	{
		pipe(pipe_fd);
		pid[i] = fork();
		if (pid[i] == 0)
			exec_command(*data, i);
		i++;
	}
	while (i != 0)
	{
		wait(NULL);
		i--;
	}
	//free data->cmd
	return (0);
}
