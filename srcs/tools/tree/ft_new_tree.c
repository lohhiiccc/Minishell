/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:41:16 by lrio              #+#    #+#             */
/*   Updated: 2024/02/27 17:45:10 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "tree.h"

t_tree	*ft_new_tree(void *content)
{
	t_tree	*new_tree;

	new_tree = malloc(sizeof(t_tree));
	new_tree->structur = content;
	return (new_tree);
}
