/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 19:46:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/26 15:51:49 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "lexer.h"

char	*format(char *str)
{
	int i;
	char *res;

	res = ft_strdup(str);
	free (str);
	i = ft_strlen(res) - 1;
	while (i > 0 && (res[i] == ' ' || res[i] == '\t'))
	{
		res[i] = '\0';
		i--;
	}
	return res;
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
	last = NONE;
	ft_memset(parenthese, 0, sizeof(int) * 2);
	i = 0;
	while (str[i])
	{
		type = get_type(str[i]);
		if ((type == T_PARENT && !ft_parenthese(str[i], parenthese)) || (type == T_OPERATOR && lexer_operator(&last, &type, str, &i)))
			return (lexer_ret(str, 0));


		if (type == T_QUOTE)
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
