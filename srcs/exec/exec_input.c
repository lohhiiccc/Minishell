/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:33:24 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/25 18:10:31 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include "exec.h"
#include "ft_printf.h"
#include "expand.h"

int	exec_input(t_tree *tree, t_fds *fds, t_env *env)
{
	int	fd;
	int	ret;

	tree->structur = expand_file((char *)tree->structur, env);
	if (NULL == (char *)tree->structur)
	{
		ft_dprintf(STDERR_FILENO, "Minichel: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	fd = open((char *)tree->structur, O_RDONLY);
	if (-1 == fd || -1 == ft_vector_add(&fds->fd_in, &fd))
	{
		ft_dprintf(STDERR_FILENO, "Minichel: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	ret = exec_args(tree->left, fds, tree->root, env);
	ft_vector_delete_elem(&fds->fd_in, fds->fd_in.nbr_elem);
	if (-1 == close(fd))
	{
		ft_dprintf(STDERR_FILENO, "Minichel: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	return (ret);
}
