/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:42:13 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/11 18:58:12 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	close_vector_fd(t_vector *fd)
{
	size_t	i;

	i = 0;
	while (i < fd->nbr_elem)
	{
		close(*(int *)(fd->addr + (i * fd->size)));
		i++;
	}
}

static char	**list_path(char **env)
{
	size_t	i;
	char	**ret;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			ret = ft_split(env[i] + 5, ':');
			return (ret);
		}
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **env)
{
	char	*ret;
	char	*temp;
	char	**path_list;
	size_t	i;

	i = 0;
	path_list = list_path(env);
	while (path_list[i])
	{
		ret = ft_strjoin(path_list[i], "/");
		temp = ft_strdup(ret);
		free(ret);
		ret = ft_strjoin(temp, cmd);
		free(temp);
		if (!access(ret, F_OK))
			return (ret);
		i++;
	}
	free(ret);
	if (!access(cmd, F_OK))
	{
		ret = ft_strdup(cmd);
		return (ret);
	}
	return (NULL);
}
