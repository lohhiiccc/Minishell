/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:43:32 by lrio              #+#    #+#             */
/*   Updated: 2024/05/02 04:14:04 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "token.h"
#include "libft.h"

int8_t	get_tokens(char *str, t_vector *vector)
{
	char	*string;
	t_token	tmp_token;
	size_t	i;

	i = 0;
	string = str;
	if (get_next_token(string + i, &tmp_token) == -1)
		return (-1);
	while (string[i])
	{
		if (i != 0)
			if (get_next_token(string + i, &tmp_token) == -1)
				return (-1);
		if (tmp_token.type != T_IS_SPACE && \
			ft_vector_add(vector, &tmp_token) == -1)
			return (-1);
		i += ft_strlen(tmp_token.str);
		if (tmp_token.type == T_IS_SPACE)
			free(tmp_token.str);
	}
	tag_files(vector);
	if (ft_vector_add(vector, &(t_token){"\n", T_NEWLINE}) == -1)
		return (-1);
	return (1);
}
