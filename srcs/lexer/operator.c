/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:29:17 by lrio              #+#    #+#             */
/*   Updated: 2024/02/26 17:53:51 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int lexer_operator(enum e_type *last, enum e_type *type, char *str, int *i)
{
	if (*last == T_OPERATOR || *last == NONE)
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
