/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:43:32 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 14:13:15 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "token.h"

int	get_tokens(char *str, t_vector *vector)
{
	char	*string;
	t_token	tmp_token;
	size_t	i;

	i = 0;
	string = str;
	if (-1 == get_next_token(string + i, &tmp_token))
		return (-1);
	while (string[i])
	{
		if (i != 0)
			if (-1 == get_next_token(string + i, &tmp_token))
				return (-1);
		if (tmp_token.type != T_IS_SPACE && \
			-1 == ft_vector_add(vector, &tmp_token))
			return (-1);
		i += ft_strlen(tmp_token.str);
		if (tmp_token.type == T_IS_SPACE)
			free(tmp_token.str);
	}
	tag_files(vector);
	for (size_t j = 0; j < vector->nbr_elem; ++j) {
		printf("type\t:%d\t| %s\n", ((t_token *)vector->addr)[j].type, ((t_token *)vector->addr)[j].str);
	}
	return (1);
}
