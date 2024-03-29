/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:42:13 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/29 03:09:05 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
#include "libft.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	close_vector_fd(t_vector *fd)
{
	size_t	i;

	i = 0;
	while (i < fd->nbr_elem)
	{
		close(*(int *)ft_vector_get(fd, i));
		i++;
	}
}

int	is_build_in(char *str)
{
	if (!ft_strcmp(str, "cd"))
		return (1);
	if (!ft_strcmp(str, "echo"))
		return (1);
	if (!ft_strcmp(str, "env"))
		return (1);
	if (!ft_strcmp(str, "exit"))
		return (1);
	if (!ft_strcmp(str, "export"))
		return (1);
	if (!ft_strcmp(str, "pwd"))
		return (1);
	if (!ft_strcmp(str, "unset"))
		return (1);
	return (0);
}

static char	**list_path(t_vector *env)
{
	char	**ret;
	char	**temp;
	size_t	i;

	i = 0;
	temp = ft_vector_get(env, i);
	while (temp)
	{
		if (!ft_strncmp(*temp, "PATH=", 5))
		{
			ret = ft_split(*temp + 5, ':');
			return (ret);
		}
		temp = ft_vector_get(env, ++i);
	}
	return (NULL);
}

char	*find_path(char *cmd, t_vector *env)
{
	char	*ret;
	char	**path_list;
	size_t	i;

	i = 0;
	path_list = list_path(env);
	while (path_list && path_list[i])
	{
		ret = ft_sprintf("%s/%s", path_list[i], cmd);
		if (!access(ret, F_OK))
		{
			ft_free_tab(path_list);
			return (ret);
		}
		free(ret);
		i++;
	}
	if (path_list)
		ft_free_tab(path_list);
	if (!access(cmd, F_OK))
	{
		ret = ft_strdup(cmd);
		return (ret);
	}
	return (NULL);
}
