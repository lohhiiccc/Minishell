/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:48:00 by lrio              #+#    #+#             */
/*   Updated: 2024/03/06 16:16:41 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"

static t_node get_redirect_type(t_token *token);
t_tree *make_redirection(t_vector *tokens)
{
	return (ft_new_tree(((t_token *)tokens->addr)[1].str,
			get_redirect_type(((t_token *)tokens->addr))));
}
static t_node get_redirect_type(t_token *token)
{
	static const t_node	node_tab[] = {HERE_DOC, APPEND, OUTPUT};
	static const char	*str_tab[] = {"<<", ">>", ">"};
	unsigned char		i;

	i = 0;
	while (i < 4)
	{
		if (0 == ft_strcmp(str_tab[i], token->str))
			return (node_tab[i]);
		i++;
	}
	return (INPUT);
}