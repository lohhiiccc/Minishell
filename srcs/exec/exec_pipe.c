/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:36:54 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/24 22:27:48 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "ft_printf.h"
#include "ms_signal.h"
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

extern int	g_sig_value;

static void	exec_left(t_tree *tree, t_fds *fds, int *fd, t_param *param);
static int	exec_right(t_tree *tree, t_fds *fds, int *fd, t_param *env);
static int	print_error(char *error, int status);

int	exec_pipe(t_tree *tree, t_fds *fds, t_param *param)
{
	int	ret;
	int	pid;
	int	fd[2];

	param->is_main = 1;
	
	ms_signal_main_wait();
	if (pipe(fd) == -1)
		return (print_error(strerror(errno), 1));
	pid = fork();
	if (pid == -1)
		return (print_error(strerror(errno), 1));
	if (pid == 0)
		exec_left(tree, fds, fd, param);
	else
	{
		if (close(fd[1]) == -1)
			ft_dprintf(2, "Minichell: pipe: %s\n", strerror(errno));
		ret = exec_right(tree, fds, fd, param);
	}
	while (wait(0) != -1)
		;
	if (g_sig_value == SIGINT)
		ft_printf("\n");
	if (g_sig_value == SIGQUIT)
		ft_printf("Quit (core dumped)\n");
	param->is_main = 0;
	return (ret);
}

static int	print_error(char *error, int status)
{
	ft_dprintf(2, "Minichell: pipe: %s\n", error);
	return (status);
}

static void	exec_left(t_tree *tree, t_fds *fds, int *fd, t_param *param)
{
	if (close(fd[0]) == -1)
	{
		ft_dprintf(2, "Minichell: pipe: %s\n", strerror(errno));
		clear_env(&param->env);
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
	}
	ft_vector_add(&fds->fd_out, &fd[1]);
	exec_args(tree->left, fds, tree->root, param);
	clear_env(&param->env);
	if (close(fd[1]) == -1)
	{
		ft_dprintf(2, "Minichell: pipe: %s\n", strerror(errno));
		clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 1);
	}
	clean_exit(tree->root, &fds->fd_in, &fds->fd_out, 0);
}

static int	exec_right(t_tree *tree, t_fds *fds, int *fd, t_param *env)
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
		clear_env(&env->env);
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
	if (WIFEXITED(ret))
		return (WEXITSTATUS(ret));
	return (1);
}
