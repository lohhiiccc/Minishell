/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:29:17 by lrio              #+#    #+#             */
/*   Updated: 2024/02/27 16:38:25 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "libft.h"

int count_str(char *str, const char *op)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_strlen(str) >= i + count && NULL != ft_strnstr(str + i + count, op, 2))
		{
			count++;
		}
		i++;
	}
	return count;
}

int lexer_operator(enum e_str_type *last, enum e_str_type *type, char *str, int *i)
{
	if (*last == T_OPERATOR || *last == T_REDIRECTION || *last == NONE)
		return (1);
	if (str[*i + 1] && str[*i + 2] && str[*i] == str[*i + 1] && (str[*i] == '|' || str[*i] == '&'))
	{
		*i +=2 ;
		*type = get_type(str[*i]);
	}
	if (str[*i + 1] && (str[*i] == '&' && str[*i + 1] != '&'))
		return (1);
	return (0);
}
