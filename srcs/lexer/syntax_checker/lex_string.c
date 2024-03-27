/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:46:57 by lrio              #+#    #+#             */
/*   Updated: 2024/03/06 17:45:33 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "token.h"
#include <stdint.h>

static size_t			get_quote_len(char *str, unsigned char *error);
static uint8_t	search_cmd(t_vector *vector, size_t i);
static uint8_t	check_str(t_vector *vector, size_t i);
uint8_t	lex_string(t_vector *vector, size_t i)
{
	t_token_type	last;

	if (i > 0)
		last = ((t_token *)vector->addr)[i - 1].type;
	else
		last = T_NONE;
	if (T_PARENTHESE_CL == last || check_str(vector, i))
		return (1);
	if (T_FILES == last)
		return (search_cmd(vector, i));
	return (0);
}

static size_t	get_quote_len(char *str, unsigned char *error)
{
	size_t	i;

	i = 1;
	if ('\'' != str[0] && '"' != str[0])
		return (0);
	while (str[i - 1] && str[i] && str[i] != str[0])
		i++;
	if (str[i] != str[0])
		*error = 1;
	if ('\'' == str[i] || '"' == str[i])
		return (i + 1 + get_quote_len(str + 1 + i, error));
	return (i + 1);
}

static uint8_t	check_str(t_vector *vector, size_t i)
{
	unsigned char	error;
	size_t			j;

	j = 0;
	while (((t_token *)vector->addr)[i].str[j])
	{
		error = 0;
		if ('\'' == ((t_token *)vector->addr)[i].str[j]
			||'"' == ((t_token *)vector->addr)[i].str[j])
			j += get_quote_len(((t_token *) vector->addr)[i].str + j, &error);
		if (error || '&' == ((t_token *)vector->addr)[i].str[j])
			return (1);
		if (((t_token *)vector->addr)[i].str[j])
			j++;
	}
	return (0);
}

static uint8_t	search_cmd(t_vector *vector, size_t i)
{
	i--;
	while (1)
	{
		if (T_PARENTHESE_CL == ((t_token *)vector->addr)[i].type)
			return (1);
		if (T_CMD == ((t_token *)vector->addr)[i].type
			|| T_LOGICAL_OP == ((t_token *)vector->addr)[i].type
			|| T_PIPE == ((t_token *)vector->addr)[i].type)
			return (0);
		if (i == 0)
			return (0);
		i--;
	}
}
