/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/04/07 22:25:35 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"
#include "ft_printf.h"
#include "prompt.h"

static uint8_t	init_fd(t_vector *fd);
static uint8_t	free_fd(t_vector *fd, uint8_t ret);
static char		*prompt_value(int last_ret);

int prompt(t_env *env)
{
	char		*str;
	static int	ptree = -1;
	t_vector	tokens;
	t_tree		*tree;
	t_vector	fd[2];

	tree = NULL;
	if (init_fd(fd))
		return (1); //todo print erreur malloc
	tokens.nbr_elem = 0;
	str = prompt_value(env->ret);
	if (!str)
	{
		ft_printf("Exit\n");
		clear_env(&env->env);
		clean_exit(tree, &fd[0], &fd[1], env->ret);
	}
	if (-1 != lexer(str, &tokens))
	{
		tree = parsing(env, &tokens);
		tree->ptree = &ptree;
		if (ptree == 1)
			print_tree(tree);
		if (NULL == tree)
			return (free_fd(fd, 1));
		env->ret = exec_args(tree, &fd[0], &fd[1], NULL);
		ft_clean_tree(tree);
	}
	if (str && str[0])
		manage_history(str);
	free(str);
	return (free_fd(fd, 1));
}

static char	*prompt_value(int last_ret)
{
	char	*str;
	char	*ret;

	if (last_ret != 0)
		str = ft_sprintf("\001\xF0\x9F\xA5\002\x9A Minichell:"); //todo : secure sprintf;
	else
		str = ft_sprintf("\001\xF0\x9F\x90\002\xA5 Minichell:"); //todo : secure sprintf;
	ret = readline(str);
	free(str);
	return (ret);
}

static uint8_t free_fd(t_vector *fd, uint8_t ret)
{
	ft_vector_free(&fd[0], NULL);
	ft_vector_free(&fd[1], NULL);
	return (ret);
}

static uint8_t init_fd(t_vector *fd)
{
	if (-1 == ft_vector_init(&fd[0], sizeof(int)))
		return (1);
	if (-1 == ft_vector_init(&fd[1], sizeof(int)))
	{
		free(fd[0].addr);
		return (1);
	}
	return (0);
}
