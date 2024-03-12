/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:30:31 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/11 23:52:12 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

static void	clean_struct(t_env *env)
{
	if (env->var)
		free(env->var);
	if (env->var_name)
		free(env->var_name);
	free(env);
	
}

static t_env	*init_struct(char *env_i)
{
	t_env	*ret;
	size_t	n;

	n = 0;
	while (env_i[n] && env_i[n] != '=')
		n++;
	ret = malloc(sizeof(t_env));
	if (!ret)
		return (NULL);
	ret->var = ft_strdup(ft_strchr(env_i, '=') + 1);
	ret->var_name = ft_strndup(env_i, n);
	if (!ret->var || !ret->var_name)
	{
		clean_struct(ret);
		return (NULL);
	}
	return (ret);
}

int	init_env(char **env, t_vector *new_env)
{
	size_t		i;
	t_env		*temp;

	i = 0;
	if (ft_vector_init(new_env, sizeof(t_env)) == -1)
		return (-1);
	while (env[i])
	{
		temp = init_struct(env[i]);
		if (!temp || ft_vector_add(new_env, temp) == -1)
		{
			while (new_env->nbr_elem > 0)
			{
				clean_struct(ft_vector_get(new_env, new_env->nbr_elem));
				new_env->nbr_elem--;
			}
			return (-1);
		}
		free(temp);
		i++;
	}
	return (0);
}
