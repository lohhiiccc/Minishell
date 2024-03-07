/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:12:38 by lrio              #+#    #+#             */
/*   Updated: 2024/03/07 15:03:33 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tree.h"
#include "token.h"

static void *free_command(t_cmd *content);
static char	**get_cmd(t_vector *tokens);
static size_t get_cmd_len(t_vector *tokens);

t_tree	*make_command(t_vector *tokens)
{
	t_cmd		*content;

	content = malloc(sizeof(t_cmd));
	if (NULL == content)
		return (NULL);
	content->arg = get_cmd(tokens);
	if (NULL == content->arg)
		return (free_command(content));
	content->path = NULL;
	content->env = NULL;
	return (ft_new_tree(content, CMD));
}

static char	**get_cmd(t_vector *tokens)
{
	size_t	i;
	size_t	len;
	char 	**arg;

	printf("%d\n", ((t_token *)tokens->addr)[0].type);
	arg = ft_calloc((get_cmd_len(tokens) + 1), sizeof(char *));
	if (NULL == arg)
		return (NULL);
	i = 1;
	arg[0] = ((t_token *)tokens->addr)[i].str;
	len = 1;
	while (((t_token *)tokens->addr)[i].type != T_CMD && ((t_token *)tokens->addr)[i].type != T_NEWLINE)
	{
		if (((t_token *)tokens->addr)[i].type == T_ARG)
		{
			arg[len] = ((t_token *)tokens->addr)[i].str;
			len++;
		}
		i++;
	}
	return (arg);
}

static size_t get_cmd_len(t_vector *tokens)
{
	size_t	len;
	size_t	i;

	i = 1;
	len = 1;
	while (((t_token *)tokens->addr)[i].type != T_CMD && ((t_token *)tokens->addr)[i].type != T_NEWLINE)
	{
		if (((t_token *)tokens->addr)[i].type == T_ARG)
			len++;
		i++;
	}
	return len;
}

static void *free_command(t_cmd *content)
{
	free(content);
	return (NULL);
}
