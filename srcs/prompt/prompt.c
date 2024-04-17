/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 15:29:07 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"
#include "ft_printf.h"
#include "prompt.h"
#include <unistd.h>

static uint8_t init_fd(t_fds *fd);
static uint8_t free_fd(t_fds *fd, uint8_t ret);

int prompt(t_env *env)
{
	char		*str;
	t_vector	tokens;
	t_tree		*tree;
	t_fds		fd;

	tree = NULL;
	if (init_fd(&fd))
		return (1); //todo print erreur malloc
	tokens.nbr_elem = 0;
	str = prompt_value(env->ret);
	if (!str)
	{
		ft_printf("Exit\n");
		clear_env(&env->env);
		clean_exit(tree, &fd.fd_in, &fd.fd_out, env->ret);
	}
	if (-1 != lexer(str, &tokens))
	{
		tree = parsing(env, &tokens);
		if (NULL == tree)
			return (free_fd(&fd, 1));
		if (env->ptree == 1)
			print_tree(tree);
		env->ret = exec_args(tree, &fd, NULL, env);
		ft_clean_tree(tree);
	}
	if (str && str[0])
		manage_history(str);
	free(str);
	return (free_fd(&fd, 1));
}

static uint8_t free_fd(t_fds *fd, uint8_t ret)
{
	ft_vector_free(&fd->fd_in, NULL);
	ft_vector_free(&fd->fd_out, NULL);
	return (ret);
}

static uint8_t init_fd(t_fds *fd)
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
