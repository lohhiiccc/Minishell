/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:46:57 by lrio              #+#    #+#             */
/*   Updated: 2024/02/29 04:36:45 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "token.h"

int	lex_string(t_vector *vector, size_t i)
{
	int	j;

	j = 0;
	while (((t_token *)vector->addr)[i].str[j])
	{
		if (((t_token *)vector->addr)[i].str[j] == '&')
			return (1);
		j++;
	}
	return (0);
}
