/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:37:24 by csteylae          #+#    #+#             */
/*   Updated: 2024/09/05 15:32:30 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

static void	redirect_io(t_shell *shell, int new_fd_in, int new_fd_out)
{
	if (dup2(STDIN_FILENO, new_fd_in) < 0)
		exit_error(shell, "dup2");
	if (dup2(STDOUT_FILENO, new_fd_out) < 0)
		exit_error(shell, "dup2");
}

//static void	close_fd(t_shell *shell, int n_cmd, int pipe_fd[2], int fd_prev)
//{
//	int	first_cmd;
//	int	last_cmd;
//
//	first_cmd = 0;
//	last_cmd = shell->tab_size;
//	if (n_cmd == first_cmd)
//		close(pipe_fd[READ_FROM]);
//	else if (n_cmd == last_cmd)
//		close(pipe_fd[WRITE_TO]);
//	else
//		close(pipe_fd[READ_FROM]);
//	return;
//}

static void	redirect_pipeline(t_shell *shell, int i, int pipe_fd[2], int fd_prev)
{
	int	first_cmd;
	int	last_cmd;

	first_cmd = 0;
	last_cmd = shell->tab_size;
	if (i == first_cmd)
	{
		close(pipe_fd[READ_FROM]);
		redirect_io(shell, STDIN_FILENO, pipe_fd[WRITE_TO]);
	}
	else if (i == last_cmd)
	{
		close(pipe_fd[WRITE_TO]);
		redirect_io(shell, fd_prev, STDOUT_FILENO);
		close(fd_prev);
	}
	else
	{
		close(pipe_fd[READ_FROM]);
		redirect_io(shell, fd_prev, pipe_fd[WRITE_TO]);
		close(fd_prev);
	}
}

static void wait_children(pid_t *child_pid, int i)
{
	while (i != 0)
	{
		wait(NULL);
		i--;
	}
	free(child_pid);
}

void	exec_pipeline(t_shell *shell)
{
	int	i;
	int	pipe_fd[2];
	pid_t *child_pid;
	int	prev_fd;

	i = 0;
	child_pid = malloc(sizeof(*child_pid) * shell->tab_size);
	if (!child_pid)
		exit_error(shell, "malloc");
	prev_fd = 0;
	while (i != shell->tab_size) //while command arent executed
	{
		//perform_redirections_files()
		pipe(pipe_fd);
		if (pipe_fd < 0)
			exit_error(shell, "pipe");
		child_pid[i] = fork();
		if (child_pid[i] < 0)
			exit_error(shell, "fork");
		else if (child_pid[i] == 0)
		{
			redirect_pipeline(shell, i, pipe_fd, prev_fd);
			exec_command(shell, i);
		}
		close(pipe_fd[WRITE_TO]);
		prev_fd = pipe_fd[READ_FROM];
		close(pipe_fd[READ_FROM]);
		i++;
	}
	wait_children(child_pid, i);
}
