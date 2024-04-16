/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:47:02 by lrio              #+#    #+#             */
/*   Updated: 2024/04/07 22:30:57 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "ft_printf.h"

static void _print_tree(t_tree *root, int space);
static void	format(enum e_node type, char *s);

void print_tree(t_tree *root)
{
	ft_printf("<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->\n");
	_print_tree(root, 0);
	ft_printf("\n\n<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->-<->\n");
}

static void _print_tree(t_tree *root, int space)
{
	if (root == NULL)
		return;
	space += PTREE_INDENT;
	_print_tree(root->right, space);
	ft_printf("\n");
	for (int i = PTREE_INDENT; i < space; i++)
		ft_printf(" ");
	if (root->type == CMD)
	{
		int i = 0;
		while (((t_cmd *)root->structur)->arg[i] != NULL)
		{
			ft_printf("%s ", ((t_cmd *)root->structur)->arg[i]);
			i++;
		}
	}
	format(root->type, (char *)root->structur);
	_print_tree(root->left, space);
}

static void	format(enum e_node type, char *s)
{
	if (type == INPUT)
		ft_printf("<:%s", s);
	if (type == OUTPUT)
		ft_printf(">:%s", s);
	if (type == HERE_DOC)
		ft_printf("<<:%s",s);
	if (type == APPEND)
		ft_printf(">>:%s", s);
	if (type == O_AND)
		ft_printf("&&");
	if (type == O_OR)
		ft_printf("||");
	if (type == O_PIPE)
		ft_printf("|");
}
