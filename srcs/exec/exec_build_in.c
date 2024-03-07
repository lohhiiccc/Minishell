/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_build_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:39:06 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/07 01:45:41 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build_in.h"

int	exec_build_in(char **arg)
{
	if (!ft_strcmp(arg[0], "echo"))
		ft_echo(arg);
	else if (!ft_strcmp(arg[0], "cd"))
		ft_cd();
	else if (!ft_strcmp(arg[0], "pwd"))
		ft_pwd();
	else if (!ft_strcmp(arg[0], "export"))
		ft_export();
	else if (!ft_strcmp(arg[0], "unset"))
		ft_unset();
	else if (!ft_strcmp(arg[0], "env"))
		ft_env();
	else if (!ft_strcmp(arg[0], "exit"))
		ft_exit();
	else
	{
		write(2, "NOOB\n", 5);
		return (1);
	}
	return (0);
}
