/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:34 by lrio              #+#    #+#             */
/*   Updated: 2024/04/24 22:06:03 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

int	ft_env(t_param *param, t_vector *fd_out)
{
	int	fd;

	if (fd_out->nbr_elem)
		fd = *(int *)ft_vector_get(fd_out, fd_out->nbr_elem - 1);
	else
		fd = 1;
	ft_vector_iteri_fd(&param->env, ft_vector_print_str_fd, fd);
	return (0);
}
