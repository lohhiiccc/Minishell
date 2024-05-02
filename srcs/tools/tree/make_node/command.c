/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:12:38 by lrio              #+#    #+#             */
/*   Updated: 2024/05/02 04:27:09 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tree.h"
#include "token.h"
#include "libft.h"

static void		*free_and_return_null(void *content);
static char		**get_cmd(t_token *tokens);
static size_t	get_cmd_len(t_token *tokens);
static void		*free_range(char **tab);

t_tree	*make_command(t_token *tokens, t_tree *root)
{
	t_cmd	*content;

	content = malloc(sizeof(t_cmd));
	if (content == NULL)
		return (NULL);
	content->arg = get_cmd(tokens);
	if (content->arg == NULL)
		return (free_and_return_null(content));
	content->path = NULL;
	return (ft_new_tree(content, CMD, root));
}

static char	**get_cmd(t_token *tokens)
{
	size_t	i;
	size_t	len;
	char	**arg;

	arg = ft_null_alloc((get_cmd_len(tokens) + 1), sizeof(char *));
	if (arg == NULL)
		return (NULL);
	i = 1;
	arg[0] = ft_strdup(tokens[0].str);
	if (!arg[0])
		return (free_and_return_null(arg));
	len = 1;
	while (tokens[i].type != T_CMD && tokens[i].type != T_NEWLINE)
	{
		if (T_ARG == tokens[i].type)
		{
			arg[len] = ft_strdup(tokens[i].str);
			if (arg[len] == NULL)
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
	while (tokens[i].type != T_CMD && tokens[i].type != T_NEWLINE)
	{
		if (tokens[i].type == T_ARG)
			len++;
		i++;
	}
	return (len);
}

static void	*free_range(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i] != NULL)
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
