/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitry_function.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:00:49 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/01 18:24:25 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITRY_FUNCTION_H

# define MINITRY_FUNCTION_H

#include "minitry_struct.h"
#include "minitry_lib.h"

/*file src/environment/init_env.c */
char	**init_env(char **envp);

/*file src/environment/test_env.c */
void	ft_print_cmd(t_data *data);
void	test_env(t_data *data, char *input); //function added to your minitry.c to avoid the pollution of minitry.h

/* repo builtins */
void	exec_cd(char *cmd);
void	exec_env(char *str, char **envp);

/* repo execution */
void	exec_command(t_data data, int nb); /*file exec_command.c */
int	exec_prompt(t_data *data); /* file exec_prompt.c */


#endif
