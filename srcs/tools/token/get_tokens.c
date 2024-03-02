/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 23:43:32 by lrio              #+#    #+#             */
/*   Updated: 2024/03/02 02:39:13 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "token.h"

//todo remettre les isspace avec une option de facon a ne pas en avoir plus de un a la suite
int get_tokens(char *str, t_vector *vector)
{
	char	*string;
	t_token	tmp_token;
	size_t	i;

	i = 0;
	string = str;
	while (string[i])
	{
		if (i == 0)
			tmp_token = get_next_token(string + i, str[i]);
		else
			tmp_token = get_next_token(string + i, str[i - 1]);
		if (tmp_token.type != T_IS_SPACE && \
			-1 == ft_vector_add(vector, &tmp_token))
			return (-1);
		i += ft_strlen(tmp_token.str);
		if (tmp_token.type == T_IS_SPACE)
			free(tmp_token.str);
	}
	return (1);
}
