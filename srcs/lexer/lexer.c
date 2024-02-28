/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/28 23:27:14 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "lexer.h"

int	get_tokens(char *str, t_vector *vector)
{
	char	*string;
	t_token	tmp_token;
	size_t	i;

	i = 0;
	string = str;
	while (string[i])
	{
		tmp_token = get_next_token(string + i);
		if (tmp_token.type != IS_SPACE && \
			-1 == ft_vector_add(vector, &tmp_token))
			return (-1);
		i += ft_strlen(tmp_token.str);
		if (tmp_token.type == IS_SPACE)
			free(tmp_token.str);
	}
	return (1);
}

void	free_token(t_vector *vector)
{
	size_t	i;

	i = 0;
	while (i < vector->nbr_elem)
	{
		free(((t_token *)vector->addr)[i].str);
		i++;
	}
	free(vector->addr);
}

int	lexer(char *str)
{
	t_vector	vector;

	if (-1 == vector_init(&vector, sizeof(t_token)))
		return (0);
	if (-1 == get_tokens(str, &vector))
		return (0);
	free_token(&vector);
	return (1);
}
