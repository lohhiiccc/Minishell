/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/03/17 16:41:11 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include "exec.h"
#include "ft_printf.h"
#include <stdlib.h>

static unsigned char init_fd(t_vector *fd);
static unsigned char free_fd(t_vector *fd, unsigned char ret);
static char *prompt_value();

int prompt(t_vector *env)
{
	char		*str;
	t_vector	tokens;
	t_tree		*tree;
	t_vector	fd[2];

	if (init_fd(fd))
		return (1); // todo print erreur malloc
	tokens.nbr_elem = 0;
	str = prompt_value();
	if (!str)
		return (free_fd(fd, 0));
	if (-1 != lexer(str, &tokens))
	{
		tree = parsing(env, &tokens);
		if (NULL == tree)
			return (free_fd(fd, 1));
		exec_args(tree, &fd[0], &fd[1]);
	}
	if (str && str[0])
		add_history(str);
	return (free_fd(fd, 1));
}

static char *prompt_value()
{
	char *str;
	char *ret;

	ret = NULL;
	str = ft_sprintf("minichel%s%c", ": ",'\0'); //todo : secure sprintf;
	ret = readline(str);
	free(str);
	return (ret);
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