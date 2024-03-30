/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:27:16 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 13:16:19 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "make_tree.h"

uint8_t	is_redirection(t_node root_type)
{
	return (root_type == APPEND
		|| root_type == HERE_DOC
		|| root_type == INPUT
		|| root_type == OUTPUT);
}

uint8_t	is_operator(t_node root_type)
{
	return ((root_type == O_OR || root_type == O_AND));
}
