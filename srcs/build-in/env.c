/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:34 by lrio              #+#    #+#             */
/*   Updated: 2024/04/03 15:58:44 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

int	ft_env(t_cmd *cmd)
{
	ft_vector_iteri(cmd->env.env, ft_vector_print_str);
	return (0);
}
