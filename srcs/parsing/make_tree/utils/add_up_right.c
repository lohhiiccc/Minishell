/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_up_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:01:13 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 22:01:15 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "add_tree.h"

t_tree	*add_up_right(t_tree *root, t_tree *new)
{
	new->left = root;
	return (new);
}
