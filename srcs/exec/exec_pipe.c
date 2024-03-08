/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:36:54 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/08 04:13:24 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <sys/wait.h>



int	exec_pipe(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	ret;
	int	pid1;
	int	pid2;
	int	fd[2];

	if (pipe(fd) == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	pid1 = fork();
	if (pid1 == -1)
		clean_exit(tree, fd_in, fd_out, 1);
	if (pid1 == 0)
	{
		if (close(fd[0]))
			clean_exit(tree, fd_in, fd_out, 1);
		ft_vector_add(fd_out, &fd[1]);
		exec_args(tree->left, fd_in, fd_out);
	}
	if (pid1 != 0)
	{
		if (close(fd[1]))
			clean_exit(tree, fd_in, fd_out, 1);
		pid2 = fork();
		if (pid2 == -1)
			clean_exit(tree, fd_in, fd_out, 1);
		if (pid2 == 0)
		{
			ft_vector_add(fd_in, &fd[0]);
			ret = exec_args(tree->right, fd_in, fd_out);
		}
	}
	if (close(fd[0]))
		clean_exit(tree, fd_in, fd_out, 1);
	while (wait(0) != -1)
		;
	return (ret);
}
