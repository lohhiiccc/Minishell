/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:38:53 by lrio              #+#    #+#             */
/*   Updated: 2024/02/27 17:39:47 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "stdlib.h"

void	ft_clean_tree(t_tree *tree)
{
	if (!tree)
		return ;
	ft_clean_tree(tree->left);
	ft_clean_tree(tree->right);
	free(tree);
}
