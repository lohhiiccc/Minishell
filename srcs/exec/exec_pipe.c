/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:36:54 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 19:53:37 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "ft_printf.h"
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

static void	exec_left(t_tree *tree, t_fds *fds, int *fd, t_env *env);
static int	exec_right(t_tree *tree, t_fds *fds, int *fd, t_env *env);
static int	print_error(char *error, int status);

int	exec_pipe(t_tree *tree, t_fds *fds, t_env *env)
{
	int	ret;
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		return (print_error(strerror(errno), 1));
	pid = fork();
	if (pid == -1)
		return (print_error(strerror(errno), 1));
	if (pid == 0)
		exec_left(tree, fds, fd, env);
	else
	{
		if (close(fd[1]) == -1)
			ft_dprintf(2, "Minichell: pipe: %s\n", strerror(errno));
		ret = exec_right(tree, fds, fd, env);
	}
	while (wait(0) != -1)
		;
	return (ret);
}

static int	print_error(char *error, int status)
{
	ft_dprintf(2, "Minichell: pipe: %s\n", error);
	return (status);
}

static void	exec_left(t_tree *tree, t_fds *fds, int *fd, t_env *env)
{
	if (close(fd[0]) == -1)
	{
		ft_dprintf(2, "Minichell: pipe: %s\n", strerror(errno));
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
	}
	ft_vector_add(&fds->fd_out, &fd[1]);
	exec_args(tree->left, fds, tree->root, env);
	if (close(fd[1]) == -1)
	{
		ft_dprintf(2, "Minichell: pipe: %s\n", strerror(errno));
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
	}
	clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 0);
}

static int	exec_right(t_tree *tree, t_fds *fds, int *fd, t_env *env)
{
	int	ret;
	int	pid;

	pid = fork();
	if (pid == -1)
		return (print_error(strerror(errno), 1));
	if (pid == 0)
	{
		ft_vector_add(&fds->fd_in, &fd[0]);
		ret = exec_args(tree->right, fds, tree->root, env);
		if (close(fd[0]) == -1)
		{
			ft_dprintf(2, "Minichell: pipe: %s\n", strerror(errno));
			clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
		}
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, ret);
	}
	else if (close(fd[0]) == -1)
		return (print_error(strerror(errno), 1));
	waitpid(pid, &ret, 0);
	return (WEXITSTATUS(ret));
}
