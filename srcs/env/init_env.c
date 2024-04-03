/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:30:31 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/21 12:10:29 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "vector.h"
#include <stdlib.h>

//int	init_env(char **env, t_vector *new_env)
//{
//	size_t	i;
//
//	i = 0;
//	if (ft_vector_init(new_env, sizeof(char *)) == -1)
//		return (-1);
//	while (env[i])
//	{
//		if (ft_vector_add_ptr(new_env, env[i]) == -1)
//		{
//			while (i > 0)
//			{
//				free(ft_vector_get(new_env, i));
//				i--;
//			}
//			return (-1);
//		}
//		i++;
//	}
//	ft_vector_add_ptr(new_env, NULL);
//	return (0);
//}
//
int	init_env(char **env, t_vector *new_env)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (ft_vector_init(new_env, sizeof(char *)) == -1)
		return (-1);
	while (env[i])
	{
		temp = ft_strdup(env[i]);
		if (!temp || ft_vector_add_ptr(new_env, temp) == -1)
		{
			while (i > 0)
			{
				free(ft_vector_get(new_env, i));
				i--;
			}
			return (-1);
		}
		i++;
	}
	ft_vector_add_ptr(new_env, NULL);
	return (0);
}
