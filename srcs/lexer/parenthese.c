/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthese.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:57:36 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 01:39:58 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "token.h"

int	parenthese_op(t_vector *vector, size_t *parent, size_t i)
{
	if (i > 0 && ((t_token *)vector->addr)[i - 1].type == CHAR)
		return (1);
	parent[0]++;
	return (0);
}

int parenthese_cl(size_t *parent)
{
	parent[1]++;
	if (parent[0] != parent[1])
		return (1);
	return (0);
}