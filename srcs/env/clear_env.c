/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:40:30 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/23 18:20:43 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"
#include "env.h"
#include "ft_printf.h"

void	clear_env(t_vector *env)
{
	char	**test;
	size_t	i;

	i = 0;
	test = ft_vector_get(env, 0);
	while (i < env->nbr_elem)
	{
		free(test[i]);
		i++;
	}
	free(env->addr);
}
