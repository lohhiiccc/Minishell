/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:34 by lrio              #+#    #+#             */
/*   Updated: 2024/04/07 21:14:39 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

int	ft_env(t_cmd *cmd, t_vector *fd_out)
{
	int	fd;

	if (fd_out->nbr_elem)
		fd = *(int *)ft_vector_get(fd_out, fd_out->nbr_elem - 1);
	else
		fd = 1;
	ft_vector_iteri_fd(&cmd->env->env, ft_vector_print_str_fd, fd);
	return (0);
}
