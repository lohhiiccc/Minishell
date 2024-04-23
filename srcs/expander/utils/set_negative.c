/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_negative.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:11:34 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 20:11:54 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"

void	set_snegative(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
				i++;
		}
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i])
			{
				str[i] = -str[i];
				i++;
			}
		}
		if (str[i])
			i++;
	}
}

void	set_negative(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"' && str[i])
			{
				if (str[i] > 0)
					str[i] = -str[i];
				i++;
			}
		}
		if (str[i])
			i++;
	}
}
