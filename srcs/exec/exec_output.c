/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:34:56 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/07 20:54:47 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "ft_printf.h"
#include "expand.h"
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	exec_output(t_tree *tree, t_fds *fds, t_env *env)
{
	int	fd;
	int	ret;

	if (-1 == expand_file((char *)tree->structur, env))
		return (1);
	fd = open((char *)tree->structur, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	ft_vector_add(&fds->fd_out, &fd);
	ret = exec_args(tree->left, fds, tree->root, env);
	ft_vector_delete_elem(&fds->fd_out, fds->fd_out.nbr_elem);
	if (close(fd))
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	return (ret);
}
