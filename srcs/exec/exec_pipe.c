/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:36:54 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/08 05:01:09 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <sys/wait.h>

static void	exec_left(t_tree *tree, t_vector *fd_in, t_vector *fd_out, int *fd)
{
	if (close(fd[0]) == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	ft_vector_add(fd_out, &fd[1]);
	exec_args(tree->left, fd_in, fd_out);
}

static int	exec_right(t_tree *tree, t_vector *fd_in, t_vector *fd_out, int *fd)
{
	int	ret;
	int	pid;

	if (close(fd[1]) == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	pid = fork();
	if (pid == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	if (pid == 0)
	{
		ft_vector_add(fd_in, &fd[0]);
		ret = exec_args(tree->right, fd_in, fd_out);
	}
	if (pid != 0)
	{
		if (close(fd[0]) == -1)
			clean_exit(tree, fd_in, fd_out, 1);
	}
	return (ret);
}

int	exec_pipe(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	ret;
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	pid = fork();
	if (pid == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	if (pid == 0)
		exec_left(tree, fd_in, fd_out, fd);
	if (pid != 0)
		ret = exec_right(tree, fd_in, fd_out, fd);
	while (wait(0) != -1)
		;
	return (ret);
}
