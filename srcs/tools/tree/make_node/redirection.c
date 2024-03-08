/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:48:00 by lrio              #+#    #+#             */
/*   Updated: 2024/03/07 23:10:51 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tree.h"
#include "token.h"

static t_node	get_redirect_type(t_token *token);

t_tree	*make_redirection(t_token *tokens)
{
	return (ft_new_tree(ft_strdup(tokens[1].str),
		get_redirect_type(tokens)));
}

static t_node	get_redirect_type(t_token *token)
{
	static const t_node	node_tab[] = {HERE_DOC, APPEND, OUTPUT};
	static const char	*str_tab[] = {"<<", ">>", ">"};
	int 				i;

	i = 0;
	while (i < 3)
	{
		if (0 == ft_strncmp(str_tab[i], token[0].str, -1))
			return (node_tab[i]);
		i++;
	}
	return (INPUT);

}
