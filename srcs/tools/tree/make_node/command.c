/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:12:38 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 22:20:14 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "expand.h"
#include "token.h"
#include <stdlib.h>
#include "libft.h"

static void		*free_and_return_null(void *content);
static char		**get_cmd(t_token *tokens);
static size_t	get_cmd_len(t_token *tokens);
static void		*free_range(char **tab);

t_tree	*make_command(t_token *tokens, t_env *env, t_tree *root)
{
	t_cmd	*content;

	content = malloc(sizeof(t_cmd));
	if (NULL == content)
		return (NULL);
	content->arg = get_cmd(tokens);
	if (NULL == content->arg)
		return (free_and_return_null(content));
	content->path = NULL;
	content->env = env;
	return (ft_new_tree(content, CMD, root));
}

static char	**get_cmd(t_token *tokens)
{
	size_t	i;
	size_t	len;
	char	**arg;

	arg = ft_null_alloc((get_cmd_len(tokens) + 1), sizeof(char *));
	if (NULL == arg)
		return (NULL);
	i = 1;
	arg[0] = ft_strdup(tokens[0].str);
	if (NULL == arg[0])
		return (free_and_return_null(arg));
	len = 1;
	while (T_CMD != tokens[i].type && T_NEWLINE != tokens[i].type)
	{
		if (T_ARG == tokens[i].type)
		{
			arg[len] = ft_strdup(tokens[i].str);
			if (NULL == arg[len])
				return (free_range(arg));
			len++;
		}
		i++;
	}
	return (arg);
}

static size_t	get_cmd_len(t_token *tokens)
{
	size_t	len;
	size_t	i;

	i = 1;
	len = 1;
	while (T_CMD != tokens[i].type && T_NEWLINE != tokens[i].type)
	{
		if (T_ARG == tokens[i].type)
			len++;
		i++;
	}
	return (len);
}

static void	*free_range(char **tab)
{
	size_t	i;

	i = 0;
	while (NULL != tab[i])
	{
		free(tab[i]);
		i++;
	}
	return (free_and_return_null(tab));
}

static void	*free_and_return_null(void *content)
{
	free(content);
	return (NULL);
}
