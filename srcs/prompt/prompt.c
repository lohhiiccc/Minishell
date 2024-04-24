/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/04/24 03:09:04 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"
#include "ft_printf.h"
#include "prompt.h"
#include "ms_signal.h"
#include <unistd.h>

extern int	g_sig_value;

static uint8_t	init_fd(t_fds *fd);
static uint8_t	free_fd(t_fds *fd, uint8_t ret);
static int		create_and_exec_tree(t_env *env, t_fds *fd, t_vector *tokens);

int	prompt(t_env *env)
{
	char		*str;
	t_vector	tokens;
	t_fds		fd;

	ms_signal_main();
	tokens.nbr_elem = 0;
	str = prompt_value(env->ret);
	if (!str)
	{
		ft_printf("Exit\n");
		clear_env(&env->env);
		exit(env->ret);
	}
	if (g_sig_value != 0)
	{
		free(str);
		env->ret = 128 + g_sig_value;
		return (128 + g_sig_value);
	}
	if (init_fd(&fd))
		return (1); //todo print erreur malloc
	if (-1 != lexer(str, &tokens, env)
		&& 1 == create_and_exec_tree(env, &fd, &tokens))
		return (1);
	if (str && str[0])
		manage_history(str);
	free(str);
	return (free_fd(&fd, 1));
}

static int	create_and_exec_tree(t_env *env, t_fds *fd, t_vector *tokens)
{
	t_tree	*tree;

	tree = parsing(env, tokens);
	if (NULL == tree)
		return (free_fd(fd, 1));
	if (env->ptree == 1)
		print_tree(tree);
	env->ret = exec_args(tree, fd, NULL, env);
	ft_clean_tree(tree);
	return (0);
}

static uint8_t	free_fd(t_fds *fd, uint8_t ret)
{
	ft_vector_free(&fd->fd_in, NULL);
	ft_vector_free(&fd->fd_out, NULL);
	return (ret);
}

static uint8_t	init_fd(t_fds *fd)
{
	if (-1 == ft_vector_init(&fd->fd_in, sizeof(int)))
		return (1);
	if (-1 == ft_vector_init(&fd->fd_out, sizeof(int)))
	{
		free(fd->fd_in.addr);
		return (1);
	}
	return (0);
}
