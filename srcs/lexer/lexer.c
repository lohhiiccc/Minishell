/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/25 18:00:21 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exec.h"
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
	enum e_type	last;

	ft_memset(parenthese, 0, sizeof(int) * 2);
	i = 0;
	while (str[i])
	{
		last = get_type(str[i]);
		if (last == T_PARENT && !ft_parenthese(str[i], parenthese))
			return (0);

//		if (last == T_OPERATOR)
//		{
//
//		}

		if (last == T_QUOTE)
			skip_quote(str, &i);
		if (!str[i])
			return (0);
		i++;
	}
	if (parenthese[0] != parenthese[1])
		return (0);
	return (1);
}
