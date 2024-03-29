/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:34:56 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/29 03:15:30 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "ft_printf.h"
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	exec_output(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	fd;
	int	ret;

	fd = open((char *)tree->structur, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_printf("OPEN FD %d\n", fd);
	if (fd == -1)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	ft_vector_add(fd_out, &fd);
//	ft_printf("ADD FD %d IN VECTOR FD_OUT\n", fd);
	ret = exec_args(tree->left, fd_in, fd_out, tree->root);
	ft_vector_delete_elem(fd_out, fd_out->nbr_elem);
//	ft_printf("DELETE FD %d IN VECTOR FD_OUT\n", fd);
	if (close(fd))
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
//	ft_printf("CLOSE VECTOR %d\n", fd);
	return (ret);
}
