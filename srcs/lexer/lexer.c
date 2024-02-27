/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/27 01:49:52 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "lexer.h"

int pipe_or_check(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((int)ft_strlen(str) >= i + count && NULL != ft_strnstr(str + i + count, "||", 2))
		{
			count++;
		}
		i++;
	}
	return count;
}

char	*format(char *str)
{
	int i;
	int j;
	char *res;

	if (ft_strlen(str) == 0)
		return (str);
	res = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (NULL == res)
		return (free(str), NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t'))
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	free(str);
	return (res);
}

int lexer_ret(char *str, int res)
{
	free(str);
	return (res);
}

int lexer(char *str)
{
	int			i;
	int 		or_check[2];
	int			parenthese[2];
	enum e_type	type;
	enum e_type last;


	or_check[0] = pipe_or_check(str);
	str = format(str);
	if (NULL == str)
		return (0);
	or_check[1] = pipe_or_check(str);
	if (or_check[0] != or_check[1])
		return (free(str), 0);
	last = NONE;
	ft_memset(parenthese, 0, sizeof(int) * 2);
	i = 0;
	while (str[i])
	{
		type = get_type(str[i]);
		if ((type == T_PARENT && !ft_parenthese(str[i], parenthese)) || (type == T_OPERATOR && lexer_operator(&last, &type, str, &i)))
			return (lexer_ret(str, 0));

		else if (type == T_QUOTE)
			skip_quote(str, &i);
		if (!str[i])
			return (lexer_ret(str, 0));
		last = type;
		i++;
	}
	if (parenthese[0] != parenthese[1] || last == T_OPERATOR)
		return (lexer_ret(str, 0));
	return (lexer_ret(str, 1));
}
