/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:26 by lrio              #+#    #+#             */
/*   Updated: 2024/04/30 02:57:00 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "env.h"
#include "ft_printf.h"
#include "vector.h"
#include "build_in.h"

int	ft_pwd(t_vector *fd_out, t_vector *env)
{
	char	*ret;
	int		fd;

	if (fd_out->nbr_elem)
		fd = *(int *)ft_vector_get(fd_out, fd_out->nbr_elem - 1);
	else
		fd = 1;
	ret = getcwd(NULL, 0);
	if (!ret)
	{
		ret = found_value_of_variable("PWD", *env);
		if (!ret)
		{
			ft_dprintf(STDERR_FILENO, ERR_PWD, strerror(errno));
			return (1);
		}
	}
	if (ft_dprintf(fd, "%s\n", ret) == -1)
	{
		ft_dprintf(STDERR_FILENO, ERR_PWD, strerror(errno));
		return (1);
	}
	free(ret);
	return (0);
}
