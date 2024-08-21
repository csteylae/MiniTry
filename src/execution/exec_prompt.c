/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:07:13 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/07 14:51:28 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

int	exec_prompt(t_shell *shell)
{
	int	i;
	int	pid;
	int	*fd;
//	int	pipe_fd[2];

	if (shell->tab_size > 1)
		exec_pipeline(shell);
	//check if pipeline
	// else check if redirections
	// check if builtins
	//if not pipeline nor builtin, idk just try to exec somthing ? Should we check if its just a variable assignment ?
	pid = fork();
	if (pid < 0)
	exit_error(shell, "fork");
	if (pid[i] == 0)
		exec_command(shell, i);
	wait(NULL);
	//need to register the exit status of last process should be attached to shell
	free_tab_cmd(shell->tab_size, shell->tab);
	return (0);
}
