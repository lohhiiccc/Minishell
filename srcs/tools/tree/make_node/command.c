/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 00:12:38 by lrio              #+#    #+#             */
/*   Updated: 2024/03/06 00:30:24 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"

static void	*free_command(t_cmd *content, t_vector *cmd);
t_tree *command(t_vector *tokens)
{
	t_cmd 		*content;
	size_t		i;
	t_vector	cmd;

	content = malloc(sizeof(t_cmd));
	if (NULL == content || -1 == ft_vector_init(&cmd, sizeof(char *)))
	{
		free(content);
		return (NULL);
	}
	i = 0;
	if (-1 == ft_vector_add(&cmd, ((t_token *)tokens->addr)[0].str))
		return (free_command(content, &cmd));
	while (((t_token *)tokens->addr)[i].type != T_CMD && ((t_token *)tokens->addr)[i].type != T_NEWLINE)
	{
		if (((t_token *)tokens->addr)[i].type == T_ARG && -1 == ft_vector_add(&cmd, ((t_token *)tokens->addr)[i].str))
			return (free_command(content, &cmd));
		i++;
	}
	content->arg = tokens->addr;
	content->env = NULL;
	content->env = NULL;
	return (ft_new_tree(content, CMD));
}

static void	*free_command(t_cmd *content, t_vector *cmd)
{
	free(content);
	ft_vector_free(cmd, &free);
	return (NULL);
}