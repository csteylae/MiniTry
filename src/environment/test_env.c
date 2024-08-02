/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:09:39 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/01 18:48:01 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitry.h"

static int	count_nb_of_cmd(char *input)
{
	int	i = 1; //we suppose there is at leat 1 command

	while (*input)
	{
		if (*input == '|')
			i++;
		input++;
	}
	return (i);
}

static void	set_all_members_to_NULL(t_command *tab, int size)
{
	int	i = 0;

	while (i != size)
	{
		tab[i].cmd = NULL;
		tab[i].in = NULL;
		tab[i].out = NULL;
		tab[i].heredoc = NULL;
		tab[i].append = NULL;
		i++;
	}
}

static void parse_cmd(t_data *data, t_command *tab, char *input)
{
	int i;
	char **input_split;
	(void)data;

	i = 0;
	input_split = ft_split(input, '|');
	while(input_split[i])
	{
		tab[i].cmd = ft_split(input_split[i], ' ');
		i++;
	}
}

static	t_command *pseudo_parsing(t_data *data, char *input)
{
	t_command *tab;
	int	nb_of_cmd;

	nb_of_cmd = count_nb_of_cmd(input);
	data->tab_size = nb_of_cmd;
	printf("nb of cmd : %d\n", data->tab_size);
	tab	= malloc(sizeof(tab) * (nb_of_cmd));
	set_all_members_to_NULL(tab, nb_of_cmd);
	parse_cmd(data, tab, input);
	return (tab);
}

void	test_env(t_data *data, char *input)
{
//	exec_cd("src/execution");
	exec_env(input, data->env);
	data->tab = pseudo_parsing(data, input);
	exec_prompt(data);
}

void	ft_print_cmd(t_data *data)
{
	int	i = 0;
	int	j = 0;

	while (i != data->tab_size)
	{
		while (data->tab[i].cmd[j] != NULL)
		{
			printf("%s\n", data->tab[i].cmd[j]);
			j++;
		}
		j = 0;
		i++;
	}
}
