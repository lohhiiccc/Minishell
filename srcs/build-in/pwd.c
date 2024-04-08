/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:26 by lrio              #+#    #+#             */
/*   Updated: 2024/04/07 21:01:23 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "vector.h"

int	ft_pwd(t_vector *fd_out)
{
	char	*ret;
	int		fd;

	if (fd_out->nbr_elem)
		fd = *(int *)ft_vector_get(fd_out, fd_out->nbr_elem - 1);
	else
		fd = 1;
	ret = getcwd(NULL, 0);
	if (!ret)
		return (1);
	if (ft_dprintf(fd, "%s\n", ret) == -1)
		return (1);
	free(ret);
	return (0);
}
