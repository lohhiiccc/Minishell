/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 00:00:13 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 13:15:14 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "make_tree.h"

t_tree	*make_tree(t_vector *tokens)
{
	size_t	i;
	t_tree	*root;
	t_tree	*new; //gestion erreur ???

	i = 0;
	root = NULL;
	while (i < tokens->nbr_elem)
	{
		new = NULL;
		if (((t_token *)tokens->addr)[i].type == T_CMD)
		{
			new = make_command(ft_vector_get(tokens, i));
			root = add_tree(root, new);
		}
		else if (((t_token *)tokens->addr)[i].type == T_LOGICAL_OP
				|| ((t_token *)tokens->addr)[i].type == T_PIPE)
		{
			new = make_operator(ft_vector_get(tokens, i));
			root = add_tree(root, new);
		}
		else if (((t_token *)tokens->addr)[i].type == T_RED_IN
				|| ((t_token *)tokens->addr)[i].type == T_RED_OUT)
		{
			new = make_redirection(ft_vector_get(tokens, i));
			root = add_tree(root, new);
		}
		print_tree(root);
		printf("\n--------------------------------\n");
		i++;
	}
	return (root);
}
