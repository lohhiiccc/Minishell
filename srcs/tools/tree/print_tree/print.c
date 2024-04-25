/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:47:02 by lrio              #+#    #+#             */
/*   Updated: 2024/04/25 03:21:02 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "ft_printf.h"

static void	_print_tree(t_tree *root, size_t space);
static void	format(t_tree *root);

void	print_tree(t_tree *root)
{
	ft_printf("<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->\n");
	_print_tree(root, 0);
	ft_printf("\n\n<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->\n");
}

static void	_print_tree(t_tree *root, size_t space)
{
	size_t	i;

	i = PTREE_INDENT;
	if (root == NULL)
		return ;
	space += PTREE_INDENT;
	_print_tree(root->right, space);
	ft_printf("\n");
	while (space > i++)
		ft_printf(" ");
	format(root);
	_print_tree(root->left, space);
}

static void	format(t_tree *root)
{
	size_t	i;

	if (root->type == CMD)
	{
		i = 0;
		while (((t_cmd *)root->structur)->arg[i] != NULL)
		{
			ft_printf("%s ", ((t_cmd *)root->structur)->arg[i]);
			i++;
		}
	}
	else if (root->type == INPUT)
		ft_printf("<:%s", (char *)root->structur);
	else if (root->type == OUTPUT)
		ft_printf(">:%s", (char *)root->structur);
	else if (root->type == HERE_DOC)
		ft_printf("<<:%s", (char *)root->structur);
	else if (root->type == APPEND)
		ft_printf(">>:%s", (char *)root->structur);
	else if (root->type == O_AND)
		ft_printf("&&");
	else if (root->type == O_OR)
		ft_printf("||");
	else if (root->type == O_PIPE)
		ft_printf("|");
}
