/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_wildecard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:55:12 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 00:55:14 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

uint8_t	have_wildcard(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*' || str[i] == '?')
			return (1);
		i++;
	}
	return (0);
}
