/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:40:48 by lrio              #+#    #+#             */
/*   Updated: 2024/03/07 00:51:06 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "make_tree.h"
/*
 *
 * (ls || ((cat && rm out) > test)) | grep ls
 * (ls || ((cat && rm out) > test))
 * ((cat && rm out) > test)
 * (cat && rm out)
 *
 */

/*
 *
 * (ls || ((cat && rm out) > test)) | grep ls
 *
 *
 *
 * 					( | )
 * 					/	\
 * 				  / 	 \
 * 				(||)	(grep ls)
 * 				/	\
 * 			  /		 \
 * 			ls		 (>)
 * 					/ 	\
 * 				  / 	 test
 * 			    (&&)
 *  		   /   \
 *  		 /      \
 *  		cat     rm out
 *
 */


/*
 * cat -e > 1 && ls
 *
 * 1: cmd
 *
 *
 */

static unsigned char is_operator(t_node type);
static t_tree *add_tree(t_tree *root, t_tree *new);

t_tree *make_tree(t_vector *tokens)
{
	size_t	i;
	t_tree *root;
	t_tree *new; //gestion erreur ???

	i = 0;
	root = NULL;
	while (i < tokens->nbr_elem)
	{
		new = NULL;
		if (((t_token *)tokens->addr)[i].type == T_CMD)
		{
			new = make_command(tokens + (i + tokens->size));
			root = add_tree(root, new);
		}
		else if (((t_token *)tokens->addr)[i].type == T_LOGICAL_OP || ((t_token *)tokens->addr)[i].type == T_PIPE)
		{
			new = make_operator(ft_vector_get(tokens, i + 1));
			root = add_tree(root, new);
		}
		else if (((t_token *)tokens->addr)[i].type == T_RED_IN || ((t_token *)tokens->addr)[i].type == T_RED_OUT)
		{
			new = make_redirection(ft_vector_get(tokens, i + 1));
			root = add_tree(root, new);
		}
		i++;
	}
	return (root);
}

static t_tree *add_tree(t_tree *root, t_tree *new)
{
	if (NULL == root)
		return (new);
	else if (root->left == NULL &&  !is_operator(root->type))
		return (add_tree(root->left, new));
	else if (root->right == NULL && !is_operator(root->type))
		return (add_tree(root->right, new));
	else
	{
		new->left = root;
		return (new);
	}
}

static unsigned char is_operator(t_node type)
{
	return (type == O_PIPE || type == O_OR || type == O_AND);
}