/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_apend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:35:32 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/29 02:58:42 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "ft_printf.h"
#include "expand.h"
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int	exec_apend(t_tree *tree, t_fds *fds, t_param *param)
{
	int	fd;
	int	ret;

	tree->structur = expand_file((char *)tree->structur, param);
	if (NULL == (char *)tree->structur)
		return (1);
	fd = open((char *)tree->structur, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	ft_vector_add(&fds->fd_out, &fd);
	ret = exec_args(tree->left, fds, tree->root, param);
	ft_vector_delete_elem(&fds->fd_out, fds->fd_out.nbr_elem);
	if (close(fd) == -1)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	return (ret);
}
