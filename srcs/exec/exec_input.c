/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:33:24 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/29 03:32:33 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "ft_printf.h"
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "expand.h"
int	exec_input(t_tree *tree, t_fds *fds, t_env *env)
{
	int	fd;
	int	ret;

	if (-1 == expand_file((char *)tree->structur, env))
		return (1);
	fd = open((char *)tree->structur, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	ft_vector_add(&fds->fd_in, &fd);
	ret = exec_args(tree->left, fds, tree->root, env);
	ft_vector_delete_elem(&fds->fd_in, fds->fd_in.nbr_elem);
	if (close(fd))
	{
		ft_dprintf(2, "Minichel: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	return (ret);
}
