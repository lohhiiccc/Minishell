/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_build_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:39:06 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/18 02:51:41 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build_in.h"
#include <unistd.h>

int	exec_build_in(t_cmd *cmd)
{
	if (!ft_strcmp(cmd->arg[0], "echo"))
		ft_echo(cmd);
	else if (!ft_strcmp(cmd->arg[0], "cd"))
		ft_cd(cmd);
	else if (!ft_strcmp(cmd->arg[0], "pwd"))
		ft_pwd(cmd);
	else if (!ft_strcmp(cmd->arg[0], "export"))
		ft_export(cmd);
	else if (!ft_strcmp(cmd->arg[0], "unset"))
		ft_unset(cmd);
	else if (!ft_strcmp(cmd->arg[0], "env"))
		ft_env(cmd);
	else if (!ft_strcmp(cmd->arg[0], "exit"))
		ft_exit(cmd);
	else
	{
		write(2, "NOOB\n", 5);
		return (1);
	}
	return (0);
}
