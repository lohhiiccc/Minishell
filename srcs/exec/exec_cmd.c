/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:37:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/29 21:40:41 by mjuffard         ###   ########lyon.fr   */
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

int	exec_cmd(t_tree *tree, t_fds *fds, t_param *param)
{
	int			ret;

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
		ret = exec_exe(tree, fds, param);
	param->ret = ret;
	return (ret);
}
