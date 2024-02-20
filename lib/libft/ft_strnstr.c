/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:43:10 by mjuffard          #+#    #+#             */
/*   Updated: 2023/11/14 23:15:28 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!big && !len)
		return (NULL);
	i = 0;
	while (big[i] && ft_strlen(little) + i <= len)
	{
		if (!ft_strncmp(&big[i], little, ft_strlen(little)))
			return (&((char *)big)[i]);
		i++;
	}
	if (!*little)
		return (&((char *)big)[0]);
	return (NULL);
}
