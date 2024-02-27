/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:42:20 by lrio              #+#    #+#             */
/*   Updated: 2024/02/27 16:36:10 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lexer.h"

int lexer_redirection(enum e_str_type *last, enum e_str_type *type, char *str, int *i)
{
	if ((*last == T_REDIRECTION) || *last == T_OPERATOR || (*last == NONE && *i != 0))
		return (1);
	if (str[*i + 1] && str[*i + 2] && str[*i] == str[*i + 1] && (str[*i] == '<' || str[*i] == '>'))
	{
		*i +=2 ;
		*type = get_type(str[*i]);
	}
//	if (*i != 0 && str[*i + 1] && (str[*i] == '<' && str[*i + 1] != '<'))
//		return (1);
//	if (*i != 0 && str[*i + 1] && (str[*i] == '>' && str[*i + 1] != '>'))
//		return (1);
	return (0);
}
