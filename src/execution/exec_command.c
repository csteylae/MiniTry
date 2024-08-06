/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:34:48 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/01 18:39:49 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

/* 
 * first construct the path from the var_env PATH, add the "/cmd" to the path 
 * then try to access the executable via access() with the X_OK flag 
 * if an access is found the command will be executed with execve() that will exit the programm
 * if no path was found we need to manage the error appropriately
 *
 * */
static void	exec_error(char **path, t_data *data, char *msg_error)
{
	if (path)
		free_tab(path);
	exit_error(data, msg_error);
}

static void	search_absolute_path(t_data *data, int n)
{
	char *path;

	if (!ft_strchr(data->tab->cmd[0], '/'))
		return;
	path = data->tab->cmd[0];
	if (access(path, X_OK) == 0)
	{
		if (execve(path, data->tab->cmd, data->env) < 0)
			exec_error(NULL, data, "execve");
	}
	exec_error(NULL, data, data->tab[n].cmd[0]);
}

static char **get_path(char **env)
{
	int	i;
	char *env_path;

	i = 0;
	env_path = NULL;
	while (env[i] && ft_strncmp("PATH=", env[i], 5))
		i++;
	env_path = env[i] + ft_strlen("PATH=");
	return (ft_split(env_path, ':'));
}

static char	*add_cmd_path(char *path, char *cmd)
{
	char *cmd_path; 

	cmd_path = ft_strjoin("/", cmd, NO_MALLOC);
	if (!cmd_path)
		return (NULL);
	path = ft_strjoin(path, cmd_path, BOTH_MALLOC);
	if (!path)
		return (NULL);
	return (path);
}

void	exec_command(t_data *data, int n)
{
	int		i;
	char	**path;

	i = 0;
	search_absolute_path(data, n);
	path = get_path(data->env);
	if (!path)
		exec_error(path, data, "malloc");
	while (path[i])
	{
		path[i] = add_cmd_path(path[i], data->tab[n].cmd[0]);
		if (!path[i])
			exec_error(path, data, "malloc");
		if (access(path[i], X_OK) == 0)
		{
			if (execve(path[i], data->tab[n].cmd, data->env) < 0)
				exec_error(path, data, "execve");
		}
		i++;
	}
	exec_error(path, data, data->tab->cmd[0]);
}
