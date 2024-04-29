/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_build_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:39:06 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/24 22:08:30 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build_in.h"
#include "env.h"

int	exec_build_in(t_tree *tree, t_fds *fds, t_param *param)
{
	int	ret;

	(void)param;
	ret = 0;
	if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "echo"))
		ret = ft_echo(((t_cmd *)tree->structur), &fds->fd_out);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "cd"))
		ret = ft_cd(((t_cmd *)tree->structur), param);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "pwd"))
		ret = ft_pwd(&fds->fd_out, &param->env);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "export"))
		ret = ft_export(((t_cmd *)tree->structur)->arg, &param->env);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "unset"))
		ret = ft_unset(((t_cmd *)tree->structur), param);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "param"))
		ret = ft_env(param, &fds->fd_out);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "exit"))
		ft_exit(tree, &fds->fd_in, &fds->fd_out, param);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "return"))
		ret = ft_atoi(((t_cmd *)tree->structur)->arg[1]);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "ptree"))
		param->ptree *= -1;
	return (ret);
}
