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

#include "tree.h"
#include "token.h"
#include "libft.h"
#include "expand.h"
#include "heredoc.h"

static t_node	get_redirect_type(t_token *token);
static	t_tree *make_heredoc(t_token *tokens, t_tree *root);

extern int g_sig_value;
//t_tree *make_redirection(t_token *tokens, t_tree *root, t_env *env)
t_tree *make_redirection(t_token *tokens, t_tree *root)
{
	t_node	type;

	type = get_redirect_type(tokens);
	if (type == HERE_DOC)
		return (make_heredoc(tokens, root));
	else
		return (ft_new_tree(ft_strdup(tokens[1].str), type, root));
}

static	t_tree *make_heredoc(t_token *tokens, t_tree *root)
{
	int8_t	tmp;
	t_tree	*new;
	size_t need_expand;

	new = ft_new_tree(ft_strdup(tokens[1].str), HERE_DOC, root);
	if (NULL == new)
		return (NULL);
	need_expand = expand_delimiter(new->structur);
	tmp = read_here_doc(new, need_expand);
	if (tmp != 0 && tmp != -1)
	{
		ft_free_tab(((char **)new->structur));
		new->structur = NULL;
		return (new);
	}
	return (new);
}

static t_node	get_redirect_type(t_token *token)
{
	static const t_node	node_tab[] = {INPUT, APPEND, OUTPUT};
	static const char	*str_tab[] = {"<", ">>", ">"};
	int					i;

	i = 0;
	while (i < 3)
	{
		if (ft_strcmp(str_tab[i], token[0].str) == 0)
			return (node_tab[i]);
		i++;
	}
	return (HERE_DOC);
}
