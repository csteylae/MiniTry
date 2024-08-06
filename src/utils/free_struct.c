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

void	free_redirection_tab(t_redirect *redir_tab)
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
		free_redirection_tab(cmd->in);
	if (cmd->out)
		free_redirection_tab(cmd->out);
	if (cmd->heredoc)
		free_redirection_tab(cmd->heredoc);
	if(cmd->append)
		free_redirection_tab(cmd->append);
	free(cmd);
	cmd = NULL;
}

void	free_tab_cmd(int size, t_cmd *tab)
{
	int	i;

	i = 0;
	while (i != size)
	{
		free_cmd(tab->cmd[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return;
	if (data->tab)
		free_cmd_tab(data->tab);
	if (data->env)
		free_tab(data->env);
	data = NULL;
}

void	exit_error(t_data *data, char *error_msg)
{
	perror(error_msg);
	free_data(data);
	exit(EXIT_FAILURE);
}
