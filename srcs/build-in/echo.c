/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:19 by lrio              #+#    #+#             */
/*   Updated: 2024/04/30 02:29:52 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "vector.h"
#include "libft.h"
#include "ft_printf.h"
#include "tree.h"
#include "build_in.h"

static int	free_and_exit(void *addr, int status);
static int	print_result(t_vector *v, int option, t_vector *fd_out);
static int	is_option(char *str);

int	ft_echo(t_cmd *cmd, t_vector *fd_out)
{
	t_vector	v;
	size_t		i;
	int			option;
	int			j;

	i = 1;
	if (ft_vector_init(&v, sizeof(char)))
		return (1);
	option = is_option(cmd->arg[1]);
	j = option;
	while (option && j)
		j = is_option(cmd->arg[++i]);
	while (cmd->arg[i])
	{
		if (ft_vector_add_n(&v, cmd->arg[i], ft_strlen(cmd->arg[i])) == -1)
			return (free_and_exit(v.addr, 1));
		if (cmd->arg[i + 1])
		{
			if (ft_vector_add(&v, " ") == -1)
				return (free_and_exit(v.addr, 1));
		}
		i++;
	}
	ft_vector_add(&v, "\0");
	return (print_result(&v, option, fd_out));
}

static int	free_and_exit(void *addr, int status)
{
	free(addr);
	if (status)
		ft_dprintf(STDERR_FILENO, ERR_ECHO, strerror(errno));
	return (status);
}

static int	is_option(char *str)
{
	size_t	i;

	i = 0;
	if (str && str[i] && str[i] == '-')
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
	}
	else
		return (0);
	if (str[i] || str[i - 1] != 'n')
		return (0);
	return (1);
}

static int	print_result(t_vector *v, int option, t_vector *fd_out)
{
	int	fd;

	if (fd_out->nbr_elem)
		fd = *(int *)ft_vector_get(fd_out, fd_out->nbr_elem - 1);
	else
		fd = 1;
	if (option)
	{
		if (ft_dprintf(fd, "%s", v->addr) == -1)
			return (free_and_exit(v->addr, 1));
	}
	else
	{
		if (ft_dprintf(fd, "%s\n", v->addr) == -1)
			return (free_and_exit(v->addr, 1));
	}
	return (free_and_exit(v->addr, 0));
}
