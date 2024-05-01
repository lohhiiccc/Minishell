/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:35:59 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 23:31:04 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "heredoc.h"

#include "heredoc.h"
#include "exec.h"
#include "ft_printf.h"

int	exec_here_doc(t_tree *tree, t_fds *fds, t_param *param)
{
	int	fd;
	int	ret;

	fd = create_file_here_doc(tree, param);
	if (-1 == fd)
	{
		ft_dprintf(STDERR_FILENO, ERROR_MSG, (char *)tree->structur,
			strerror(errno));
		return (1);
	}
	if (-1 == ft_vector_add(&fds->fd_in, &fd))
	{
		ft_dprintf(STDERR_FILENO, ERROR_MSG, (char *)tree->structur,
			strerror(errno));
		return (1);
	}
	ret = exec_args(tree->left, fds, tree->root, param);
	ft_vector_delete_elem(&fds->fd_in, fds->fd_in.nbr_elem - 1);
	if (-1 == close(fd))
	{
		ft_dprintf(STDERR_FILENO, ERROR_MSG, (char *)tree->structur,
			strerror(errno));
		return (1);
	}
	return (ret);
}
