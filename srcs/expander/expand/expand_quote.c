/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:12:19 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 20:12:24 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "libft.h"

uint8_t remove_quote(char *s)
{
	size_t	i;
	uint8_t	quote;

	quote = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == '\'' || s[i] == '"') || (s[i] == '$'
			&& (s[i + 1] == '\'' || s[i + 1] == '"')))
		{
			quote = 1;
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			continue ;
		}
		if (s[i] < 0)
			s[i] = -s[i];
		i++;
	}
	return (quote);
}
