/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:37:24 by csteylae          #+#    #+#             */
/*   Updated: 2024/09/05 12:43:22 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

static void	redirect_io(int new_fd_in, int new_fd_out)
{
	dup2(STDIN_FILENO, new_fd_in);
	dup2(STDOUT_FILENO, new_fd_out);
}

static void	close_fd(t_shell *shell, int n_cmd, int pipe_fd[2], int fd_prev)
{
	int	first_cmd;
	int	last_cmd;

	first_cmd = 0;
	last_cmd = shell->tab_size;
	if (n_cmd == first_cmd)
		close(pipe_fd[READ_FROM]);
	else if (n_cmd == last_cmd)
		close(pipe_fd[WRITE_TO]);
	else
		close(pipe_fd);
}

void	exec_pipeline(t_shell *shell)
{
	int	i;
	int	pipe_fd[2];
	int	*child_pid;
	int	prev_fd;

	i = 0;
	child_pid = malloc(sizeof(int) * shell->tab_size);
	if (!child_pid)
		exit_error(shell, "malloc");
	prev_fd = 0;
	while (i != shell->tab_size) //while command arent executed
	{
		//open files for redirection
		pipe(pipe_fd);
		if (pipe_fd < 0)
			exit_error(shell, "pipe");
		child_pid[i] = fork();
		if (child_pid[i] < 0)
			exit_error(shell, "fork");
		if (child_pid[i] == 0)
		{
			close_fd(shell, i, pipe_fd, prev_fd);
			redirect_io();
			exec_cmd();
		}
		close(pipe_fd[WRITE_TO]);
		prev_fd = pipe_fd[READ_FROM];
		i++;
	}
//	wait_children(child_pid);
}
