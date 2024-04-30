/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:25:55 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 01:11:18 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#include "vector.h"
#include "exec.h"
#include "ft_printf.h"

static char	**list_path(t_vector *env);
static char	*path_exist(char **path_list, char *cmd);

char	*find_path(char *cmd, t_vector *env)
{
	char	*ret;
	char	**path_list;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		ret = ft_strdup(cmd);
	else
	{
		path_list = list_path(env);
		ret = path_exist(path_list, cmd);
	}
	return (ret);
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
			ret = ft_split(*temp + 5, ":");
			return (ret);
		}
		temp = ft_vector_get(env, ++i);
	}
	return (NULL);
}

static char	*path_exist(char **path_list, char *cmd)
{
	size_t		i;
	char		*ret;
	struct stat	file;

	i = -1;
	if (!path_list)
		return (NULL);
	while (path_list[++i])
	{
		ret = ft_sprintf("%s/%s", path_list[i], cmd);
		if (!access(ret, F_OK))
		{
			stat(ret, &file);
			if (S_ISREG(file.st_mode))
			{
				ft_free_tab(path_list);
				return (ret);
			}
		}
		free(ret);
	}
	ft_free_tab(path_list);
	return (NULL);
}
