/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:21:54 by lrio              #+#    #+#             */
/*   Updated: 2024/02/28 20:08:43 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

char	*get_quote(char *str)
{
	size_t	i;
	char	*res;

	i = 0;
	if (str[1])
		i++;
	while (str[i] && str[i] != str[0])
		i++;
	res = ft_calloc((i + 2), sizeof(char));
	if (NULL == res)
		return (NULL);
	ft_memcpy(res, str, sizeof(char) * i + 1);
	return (res);
}
