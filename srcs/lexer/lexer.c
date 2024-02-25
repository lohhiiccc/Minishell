/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/25 20:10:41 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "lexer.h"

static enum e_type get_type(char c)
{
	if ('\'' == c || '"' == c)
		return T_QUOTE;
	if (c == '|' || c == '&' || c == '<' || c == '>')
		return T_OPERATOR;
	if ('(' == c || ')' == c)
		return T_PARENT;
	return (T_TOKEN);
}

int lexer(char *str)
{
	int			i;
	int			parenthese[2];
	enum e_type	type;
	enum e_type last;

	last = NONE;
	ft_memset(parenthese, 0, sizeof(int) * 2);
	i = 0;
	while (str[i])
	{
		type = get_type(str[i]);
		if (type == T_PARENT && !ft_parenthese(str[i], parenthese))
			return (0);

		if (type == T_OPERATOR)
		{
			if (last == T_OPERATOR || last == NONE)
				return (0);//TODO gerer <<
			if (str[i + 1] && str[i + 2] && str[i] == str[i + 1] && (str[i] == '>' ||str[i] == '<' || str[i] == '|' || str[i] == '&'))
			{
				i +=2 ;
				type = get_type(str[i]);
			}
		}

		if (type == T_QUOTE)
			skip_quote(str, &i);
		if (!str[i])
			return (0);
		last = type;
		i++;
	}
	if (parenthese[0] != parenthese[1] || last == T_OPERATOR)
		return (0);
	return (1);
}
