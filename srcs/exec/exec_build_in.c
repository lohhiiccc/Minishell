/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_build_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:39:06 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/07 21:02:59 by mjuffard         ###   ########lyon.fr   */
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
		ret = ft_echo(((t_cmd *)tree->structur), fd_out);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "cd"))
		ret = ft_cd(((t_cmd *)tree->structur));
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "pwd"))
		ret = ft_pwd(fd_out);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "export"))
		ret = ft_export(((t_cmd *)tree->structur));
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "unset"))
		ret = ft_unset(((t_cmd *)tree->structur));
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "env"))
		ret = ft_env(((t_cmd *)tree->structur), fd_out);
	else if (!ft_strcmp(((t_cmd *)tree->structur)->arg[0], "exit"))
		ft_exit(tree, fd_in, fd_out);
	return (ret);
}
