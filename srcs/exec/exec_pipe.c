/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:36:54 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/25 04:39:07 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#include "exec.h"
#include "ft_printf.h"
#include "ms_signal.h"

extern int	g_sig_value;

static void	exec_left(t_tree *tree, t_fds *fds, int *fd, t_env *env);
static int	exec_right(t_tree *tree, t_fds *fds, int *fd, t_env *env);
static int	print_error(char *error, int status);

int	exec_pipe(t_tree *tree, t_fds *fds, t_env *env)
{
	int	ret;
	int	pid;
	int	fd[2];

	env->is_main = 1;
	
	ms_signal_main_wait();
	if (-1 == pipe(fd))
		return (print_error(strerror(errno), 1));
	pid = fork();
	if (-1 == pid)
		return (print_error(strerror(errno), 1));
	if (pid == 0)
		exec_left(tree, fds, fd, env);
	else
	{
		if (-1 == close(fd[1]))
			ft_dprintf(2, "Minichel: pipe: %s\n", strerror(errno));
		ret = exec_right(tree, fds, fd, env);
	}
	while (-1 != wait(0))
		;
	if (SIGINT == g_sig_value)
		ft_printf("\n");
	if (SIGQUIT == g_sig_value)
		ft_printf("Quit (core dumped)\n");
	env->is_main = 0;
	return (ret);
}

static int	print_error(char *error, int status)
{
	ft_dprintf(2, "Minichel: pipe: %s\n", error);
	return (status);
}

static void	exec_left(t_tree *tree, t_fds *fds, int *fd, t_env *env)
{
	if (-1 == close(fd[0]) || -1 == ft_vector_add(&fds->fd_out, &fd[1]))
	{
		ft_dprintf(2, "Minichel: pipe: %s\n", strerror(errno));
		clear_env(&env->env);
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
	}
	exec_args(tree->left, fds, tree->root, env);
	clear_env(&env->env);
	clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 0);
}

static int	exec_right(t_tree *tree, t_fds *fds, int *fd, t_env *env)
{
	int	ret;
	int	pid;

	pid = fork();
	if (-1 == pid)
		return (print_error(strerror(errno), 1));
	if (0 == pid)
	{
		if (-1 == ft_vector_add(&fds->fd_in, &fd[0]))
		{
			ft_dprintf(2, "Minichel: pipe: %s\n", strerror(errno));
			clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
		}
		ret = exec_args(tree->right, fds, tree->root, env);
		clear_env(&env->env);
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, ret);
	}
	else if (-1 == close(fd[0]))
		return (print_error(strerror(errno), 1));
	waitpid(pid, &ret, 0);
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	return (1);
}
