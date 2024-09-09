/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwaslet <iwaslet@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:52:53 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/20 15:56:46 by iwaslet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

void	free_tab_char(char **tab)
{
	int	i;

	i = 0;
	if (tab && *tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
			i++;
		}
		free(tab);
		tab = NULL;
	}
}

void	free_tab_redirect(t_redirect *redir_tab)
{
	int	i;

	i = 0;
	if (!redir_tab)
		return ;
	while(redir_tab[i].filename)
	{
		free(redir_tab[i].filename);
		if (redir_tab[i].hd_delimiter)
			free(redir_tab[i].hd_delimiter);
		i++;
	}
	free(redir_tab);
}

void	free_cmd(t_command *cmd)
{
	if (!cmd)
		return;
	if (cmd->cmd)
		free_tab_char(cmd->cmd);
	if (cmd->in)
		free_tab_redirect(cmd->in);
	if (cmd->out)
		free_tab_redirect(cmd->out);
	if (cmd->heredoc)
		free_tab_redirect(cmd->heredoc);
	if(cmd->append)
		free_tab_redirect(cmd->append);
	cmd = NULL;
}

void	free_tab_cmd(int size, t_command *tab)
{
	int	i;

	i = 0;
	while (i != size)
	{
		free_cmd(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_shell(t_shell *shell)
{
	if (!shell)
		return;
	if (shell->tab)
		free_tab_cmd(shell->tab_size, shell->tab);
	if (shell->env)
		free_tab_char(shell->env);
	shell = NULL;
}
