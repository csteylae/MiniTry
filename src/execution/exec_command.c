/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:15:39 by csteylae          #+#    #+#             */
/*   Updated: 2024/07/31 11:40:16 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

void	exec_command(char **cmd, char **envp)
{
	// check if built_in
	// check for redirection
	// check if pipeline
	// fork
	// construct path
	// execve
	// wait children
}

int main(int argc, char **argv, char **envp)
{
	exec_command(argv, envp);
}
