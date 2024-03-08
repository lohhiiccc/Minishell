/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 00:47:02 by lrio              #+#    #+#             */
/*   Updated: 2024/03/08 15:41:29 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "tree.h"
#define COUNT 10

void print2DUtil(t_tree *root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;
	// Process right child first
	print2DUtil(root->left, space);

	// Print current node after space
	// count
	printf("\n");
	for (int i = COUNT; i < space; i++)
		printf(" ");
	if (root->type == CMD)
		printf("%s", ((t_cmd *)root->structur)->arg[0]);
	if (root->type == INPUT)
		printf(" < ");
	if (root->type == OUTPUT)
		printf(" > ");
	if (root->type == HERE_DOC)
		printf("<< ");
	if (root->type == APPEND)
		printf(">> ");
	if(root->type == O_AND)
		printf("&& ");
	if(root->type == O_OR)
		printf("|| ");
	if(root->type == O_PIPE)
		printf("|  ");
//	printf("%d\n", (t_)root->structur);

	// Process left child
	print2DUtil(root->right, space);
}

// Wrapper over print2DUtil()
void print2D(t_tree *root)
{
	// Pass initial space count as 0
	print2DUtil(root, 0);
	printf("\n");
}