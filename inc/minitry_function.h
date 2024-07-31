/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitry_function.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csteylae <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:00:49 by csteylae          #+#    #+#             */
/*   Updated: 2024/07/31 12:21:55 by csteylae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITRY_FUNCTION_H

# define MINITRY_FUNCTION_H

#include "minitry_struct.h"
#include "minitry_lib.h"


void	exec_cd(char *cmd);
void	exec_env(char *str, char **envp);

void	test_env(t_data *data, char *input); //function added to your minitry.c to avoid the pollution of minitry.h

#endif
