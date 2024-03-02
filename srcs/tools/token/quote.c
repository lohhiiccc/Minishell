/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:21:54 by lrio              #+#    #+#             */
/*   Updated: 2024/03/02 07:17:48 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdio.h>
#include "libft.h"

static size_t	get_len(char *str, unsigned char *error)
{
	size_t	i;

	i = 1;
	if (str[0] != '\'' && str[0] != '"')
		return 0;
	while (str[i - 1] && str[i] && str[i] != str[0])
		i++;
	if (str[i] != str[0])
		*error = 1;
	if (str[i] == '\'' || str[i] == '"')
		return (i + 1 + get_len(str + 1 + i, error));
	return (i + 1);
}

char	*get_quote(char *str)
{
	size_t			i;
	char			*res;
	unsigned char	error;

	error = 0;
	i = get_len(str, &error);
	if (error || (str[i - 1] != '\'' && str[i - 1] != '"'))
		return (NULL);
	res = malloc(sizeof(char) * i + 1);
	if (NULL == res)
		return (NULL);
	ft_memcpy(res, str, sizeof(char ) * i + 1);
	return (res);
}
