/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:43:32 by lrio              #+#    #+#             */
/*   Updated: 2024/02/28 23:51:15 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "token.h"

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
