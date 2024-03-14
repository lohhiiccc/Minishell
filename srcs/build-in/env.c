/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:34 by lrio              #+#    #+#             */
/*   Updated: 2024/03/12 18:35:06 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include <stdio.h>

int	ft_env(t_cmd *cmd)
{
	char	**temp;
	size_t	i;

	i = 0;
	temp = ft_vector_get(cmd->env, i);
	while (temp && *temp)
	{
		printf("%s\n", *temp);
		temp = ft_vector_get(cmd->env, ++i);
	}
	return (0);
}
