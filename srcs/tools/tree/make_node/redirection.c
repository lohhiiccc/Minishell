/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:48:00 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 22:20:28 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "tree.h"
#include "token.h"
#include "libft.h"
#include "expand.h"

static t_node	get_redirect_type(t_token *token);

extern int g_sig_value;
t_tree *make_redirection(t_token *tokens, t_tree *root, t_env *env)
{
	t_node	type;
	t_tree	*new;
	int8_t	tmp;

	type = get_redirect_type(tokens);
	if (HERE_DOC == type)
	{
		new = ft_new_tree(ft_strdup(tokens[1].str), type, root);
		if (NULL == new)
			return (NULL);
		expand_delimiter(new->structur);
		tmp = read_here_doc(new);
		if (tmp != 0)
		{
			free(new->structur);
			free(new);
			if (2 == g_sig_value)
				env->ret = 130;
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
