/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_down.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:59:28 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 21:59:30 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "add_tree.h"

t_tree	*add_down(t_tree *root, t_tree **branch, t_tree *leaf)
{
	*branch = add_in_subtree(*branch, leaf);
	return (root);
}
