/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_build_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:39:06 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/03 14:44:42 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "build_in.h"
#include "env.h"

int	exec_build_in(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	ret;

	ret = 0;
	if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "echo"))
		ret = ft_echo(((t_cmd *)tree->structur));
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "cd"))
		ret = ft_cd(((t_cmd *)tree->structur));
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "pwd"))
		ret = ft_pwd();
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "export"))
		ret = ft_export(((t_cmd *)tree->structur));
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "unset"))
		ret = ft_unset(((t_cmd *)tree->structur));
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "env"))
		ret = ft_env(((t_cmd *)tree->structur));
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "exit"))
	{
		clear_env(((t_cmd *)tree->structur)->env);
		clean_exit(tree->root, fd_in, fd_out, ft_atoi(((t_cmd *)tree->structur)->arg[1]));
	}
	return (ret);
}
