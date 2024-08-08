/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitry_function.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:00:49 by csteylae          #+#    #+#             */
/*   Updated: 2024/08/07 14:49:07 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITRY_FUNCTION_H

# define MINITRY_FUNCTION_H

#include "minitry_struct.h"
#include "minitry_lib.h"

/*file src/environment/init_env.c */
char	**init_env(char **envp);

/*file src/environment/test_env.c */
void	ft_print_cmd(t_shell *shell);
void	test_env(t_shell *shell, char *input); //function added to your minitry.c to avoid the pollution of minitry.h

/* repo builtins */
void	exec_cd(char *cmd);
void	exec_env(char *str, char **envp);

/* repo execution */
void	exec_command(t_shell *shell, int nb); /*file exec_command.c */
int		exec_prompt(t_shell *shell); /* file exec_prompt.c */

/* repo utils */
//file free_struct.c :
void	free_tab_char(char **tab);
void	free_tab_redirect(t_redirect *tab);
void	free_cmd(t_command *cmd);
void	free_tab_cmd(int size, t_command *tab);
void	free_shell(t_shell *shell);

//file exit_error.c
void	exit_error(t_shell *shell, char *error);


#endif
