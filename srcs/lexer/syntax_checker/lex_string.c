/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 03:46:57 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 16:25:12 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "token.h"

static unsigned char	search_cmd(t_vector *vector, size_t i);
static size_t			get_quote_len(char *str, unsigned char *error);
static unsigned char	check_str(t_vector *vector, size_t i);

unsigned char	lex_string(t_vector *vector, size_t i)
{
	t_token_type	last;

	if (i > 0)
		last = ((t_token *)vector->addr)[i - 1].type;
	else
		last = T_NONE;
	if (last == T_PARENTHESE_CL || check_str(vector, i))
		return (1);
	if (last == T_FILES)
		return (search_cmd(vector, i));
	return (0);
}

static size_t	get_quote_len(char *str, unsigned char *error)
{
	size_t	i;

	i = 1;
	if (str[0] != '\'' && str[0] != '"')
		return (0);
	while (str[i - 1] && str[i] && str[i] != str[0])
		i++;
	if (str[i] != str[0])
		*error = 1;
	if (str[i] == '\'' || str[i] == '"')
		return (i + 1 + get_quote_len(str + 1 + i, error));
	return (i + 1);
}

static unsigned char	check_str(t_vector *vector, size_t i)
{
	unsigned char	backup;
	size_t			j;

	j = 0;
	while (((t_token *)vector->addr)[i].str[j])
	{
		backup = 0;
		if (((t_token *)vector->addr)[i].str[j] == '\''
			|| ((t_token *)vector->addr)[i].str[j] == '"')
			j += get_quote_len(((t_token *) vector->addr)[i].str + j, &backup);
		if (((t_token *)vector->addr)[i].str[j] == '&' || backup)
			return (1);
		if (((t_token *)vector->addr)[i].str[j])
			j++;
	}
	return (0);
}

static unsigned char	search_cmd(t_vector *vector, size_t i)
{
	i--;
	while (i >= 0)
	{
		if (((t_token *)vector->addr)[i].type == T_PARENTHESE_CL)
			return (1);
		if (((t_token *)vector->addr)[i].type == T_CMD || ((t_token *)vector->addr)[i].type == T_LOGICAL_OP)
			return (0);
		i--;
	}
	return (1);
}
