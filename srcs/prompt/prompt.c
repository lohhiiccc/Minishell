/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 23:55:41 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "make_tree.h"
#include "minishell.h"
#include "exec.h"

static unsigned char init_fd(t_vector *fd);
static unsigned char free_fd(t_vector *fd, unsigned char ret);

int prompt(t_vector *env)
{
	char		*str;
	t_vector	tokens;
	t_tree		*tree;
	t_vector	fd[2];

	if (init_fd(fd))
		return (1); // todo print erreur malloc
	tokens.nbr_elem = 0;
	str = readline("minichel>");
	if (!str)
		return (free_fd(fd, 0));
	if (-1 != lexer(str, &tokens))
	{
		tree = make_tree(ft_vector_get(&tokens, 0), env);
		if (NULL == tree)
			return (free_fd(fd, 1));
		print_tree(tree);
//		exec_args(tree, &fd[0], &fd[1]);
	}
	if (str && str[0])
		add_history(str);
	return (free_fd(fd, 1));
}

static unsigned char free_fd(t_vector *fd, unsigned char ret)
{
	ft_vector_free(&fd[0], NULL);
	ft_vector_free(&fd[1], NULL);
	return (ret);
}

static unsigned char init_fd(t_vector *fd)
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