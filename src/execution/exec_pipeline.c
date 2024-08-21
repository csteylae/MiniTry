#include "../../inc/minitry.h"

static void	redirect_io(int new_fd_in, int new_fd_out)
{
	//should add the check errors 
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
	int	*children_pid;
	int	prev_fd;

	i = 0;
	children_pid = malloc(sizeof(int) * shell->tab_size);
	if (!children_pid)
		exit_error(shell, "malloc");
	prev_fd = 0;
	while (i != tab_size)
	{
		//open files for redirection
		pipe(pipe_fd);
		if (pipe_fd < 0)
			exit_error(shell, "pipe");
		children_pid[i] = fork();
		if (children_pid[i] < 0)
			exit_error(shell, "fork");
		if (children_pid[i] == 0)
		{
			close_fd(shell, i, pipe_fd, prev_fd);
			redirect_io();
			exec_cmd();
		}
		close();
		i++;
	}
}
