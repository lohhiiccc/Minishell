/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:47:02 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 13:19:30 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tree.h"
#define COUNT 8

void _print_tree(t_tree *root, int space)
{
	if (root == NULL)
		return;

	space += COUNT;
	_print_tree(root->right, space);

	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	if (root->type == CMD)
	{
		int i = 0;
		while (((t_cmd *)root->structur)->arg[i] != NULL)
		{
			printf("%s", ((t_cmd *)root->structur)->arg[i]);
			i++;
		}
	}
	if (root->type == INPUT)
		printf("<:%s", (char *)root->structur);
	if (root->type == OUTPUT)
		printf(">:%s", (char *)root->structur);
	if (root->type == HERE_DOC)
		printf("<<:%s", (char *)root->structur);
	if (root->type == APPEND)
		printf(">>:%s", (char *)root->structur);
	if(root->type == O_AND)
		printf("&&");
	if(root->type == O_OR)
		printf("||");
	if(root->type == O_PIPE)
		printf("|");

	_print_tree(root->left, space);
}

// Wrapper over print_tree()
void print_tree(t_tree *root)
{
	_print_tree(root, 0);
	printf("\n");
}