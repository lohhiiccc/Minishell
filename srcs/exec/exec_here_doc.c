/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:35:59 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/25 04:11:28 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

#include "exec.h"
#include "ft_printf.h"

int	exec_here_doc(t_tree *tree, t_fds *fds, t_env *env)
{
	int	fd;
	int	ret;

	fd = create_file_here_doc(tree, env);
	if (-1 == fd)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	if (-1 == ft_vector_add(&fds->fd_in, &fd))
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	ret = exec_args(tree->left, fds, tree->root, env);
	ft_vector_delete_elem(&fds->fd_in, fds->fd_in.nbr_elem);
	if (-1 == close(fd))
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	return (ret);
}
