/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 23:27:16 by lrio              #+#    #+#             */
/*   Updated: 2024/03/08 23:29:59 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "make_tree.h"

unsigned char is_redirection(t_node root_type)
{
	return (root_type == APPEND || root_type == HERE_DOC || root_type == INPUT || root_type == OUTPUT) ;
}

unsigned char is_operator(t_node root_type)
{
	return ((root_type == O_OR || root_type == O_AND)) ;
}

