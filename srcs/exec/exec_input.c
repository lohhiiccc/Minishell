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

int	exec_input(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	fd;
	int	ret;

	fd = open((char *)tree->structur, O_RDONLY);
	ft_printf("OPEN FD %d\n", fd);
	if (fd == -1)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	ft_vector_add(fd_in, &fd);
	ft_printf("ADD FD %d IN VECTOR FD_IN\n", fd);
	ret = exec_args(tree->left, fd_in, fd_out, tree->root);
	ft_vector_delete_elem(fd_in, fd_in->nbr_elem);
	ft_printf("DELETE FD %d IN VECTOR FD_IN\n", fd);
	if (close(fd))
	{
		ft_dprintf(2, "Minichel: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	ft_printf("CLOSE FD %d\n", fd);
	return (ret);
}
