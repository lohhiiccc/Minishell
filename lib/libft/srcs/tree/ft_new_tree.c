/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:46:08 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/20 13:03:50 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_tree	*ft_new_tree(void *content)
{
	t_tree	*new_tree;

	new_tree = malloc(sizeof(t_tree));
	new_tree->content = content;
	return (new_tree);
}
