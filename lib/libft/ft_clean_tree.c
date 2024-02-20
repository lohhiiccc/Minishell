/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:06:44 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 13:10:17 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean_tree(t_tree *tree)
{
	if (!tree)
		return ;
	ft_clean_tree(tree->left);
	ft_clean_tree(tree->right);
	free(tree);
}
