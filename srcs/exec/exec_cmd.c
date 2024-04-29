/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:37:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/24 22:45:39 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
#include "expand.h"

int	exec_cmd(t_tree *tree, t_fds *fds, t_param *param)
{
	int			ret;

	((t_cmd *)tree->structur)->arg = expand_cmd(((t_cmd *) tree->structur)->arg,
												param);
	if ((((t_cmd *)tree->structur)->arg) == NULL)
		return (1);
	if (is_build_in(((t_cmd *)tree->structur)->arg[0]))
		ret = exec_build_in(tree, fds, param);
	else
		ret = exec_exe(tree, fds, param);
	return (ret);
}
