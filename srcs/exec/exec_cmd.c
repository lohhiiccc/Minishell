/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:37:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 02:06:45 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "exec.h"
#include "env.h"
#include "expand.h"
#include "ft_printf.h"

static int	found_and_exec_path(t_tree *tree, t_fds *fds, t_param *param);

int	exec_cmd(t_tree *tree, t_fds *fds, t_param *param)
{
	int	ret;

	((t_cmd *)tree->structur)->arg = expand_cmd(((t_cmd *) tree->structur)->arg,
			param);
	if (!((t_cmd *)tree->structur)->arg)
	{
		ft_dprintf(STDERR_FILENO, ERROR_MSG, ((t_cmd *)tree->structur)->arg[0],
			strerror(errno));
		return (1);
	}
	if (is_build_in(((t_cmd *)tree->structur)->arg[0]))
		ret = exec_build_in(tree, fds, param);
	else
		ret = found_and_exec_path(tree, fds, param);
	param->ret = ret;
	return (ret);
}

static int	found_and_exec_path(t_tree *tree, t_fds *fds, t_param *param)
{
	int			ret;

	((t_cmd *)tree->structur)->path = find_path
		(((t_cmd *)tree->structur)->arg[0], &param->env);
	if (!((t_cmd *)tree->structur)->path)
	{
		ft_dprintf(STDERR_FILENO, CMD_NOT_FOUND,
			((t_cmd *)tree->structur)->arg[0]);
		ret = 127;
	}
	else
		ret = exec_exe(tree, fds, param);
	free(((t_cmd *)tree->structur)->path);
	return (ret);
}
