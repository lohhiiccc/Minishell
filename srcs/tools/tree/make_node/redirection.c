/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:48:00 by lrio              #+#    #+#             */
/*   Updated: 2024/03/17 16:46:53 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "token.h"
#include "libft.h"
#include "expand.h"

static t_node	get_redirect_type(t_token *token);

t_tree	*make_redirection(t_token *tokens, t_tree *root)
{
	t_node type;
	t_tree *new;

	type = get_redirect_type(tokens);
	if (HERE_DOC == type)
	{
		new = ft_new_tree(ft_strdup(tokens[1].str), type, root);
		if (NULL == new)
			return (NULL);
		expand_delimiter(new->structur);
		if (1 == create_file_here_doc(new))
		{
			ft_clean_tree(new);
			return (NULL);
		}
		return (new);
	}
	else
		return (ft_new_tree(ft_strdup(tokens[1].str), type, root));
}

static t_node	get_redirect_type(t_token *token)
{
	static const t_node	node_tab[] = {INPUT, APPEND, OUTPUT};
	static const char	*str_tab[] = {"<", ">>", ">"};
	int					i;

	i = 0;
	while (i < 3)
	{
		if (0 == ft_strcmp(str_tab[i], token[0].str))
			return (node_tab[i]);
		i++;
	}
	return (HERE_DOC);
}
