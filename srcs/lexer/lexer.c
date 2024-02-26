/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/26 20:26:48 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "lexer.h"

char	*format(char *str)
{
	int i;
	int j;
	char *res;

	if (ft_strlen(str) == 0)
		return (str);
	res = malloc(sizeof(char) * ft_strlen(str));
	if (NULL == res)
		return (NULL);
	ft_bzero(res, sizeof(char ) * ft_strlen(str));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t'))
		{
			if (j > 0 && res[j - 1] == '|' && str[i] == '|')
			{
				free(str);
				return (NULL);
			}
			res[j] = str[i];
			j++;
		}
		i++;
	}
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
	int			parenthese[2];
	enum e_type	type;
	enum e_type last;

	str = format(str);
	if (NULL == str)
		return (0);
//	printf(":%s:\n", str);
	last = NONE;
	ft_memset(parenthese, 0, sizeof(int) * 2);
	i = 0;
	while (NULL != str && str[i])
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
