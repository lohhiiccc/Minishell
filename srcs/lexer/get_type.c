/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:29:56 by lrio              #+#    #+#             */
/*   Updated: 2024/02/26 17:54:58 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

enum e_type get_type(char c)
{
	if ('\'' == c || '"' == c)
		return (T_QUOTE);
	else if (c == '|' || c == '&')
		return (T_OPERATOR);
	else if (c == '>' || c == '<')
		return (T_REDIRECTION);
	else if ('(' == c || ')' == c)
		return (T_PARENT);
	return (T_TOKEN);
}

