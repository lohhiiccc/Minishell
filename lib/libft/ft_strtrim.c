/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:48:24 by mjuffard          #+#    #+#             */
/*   Updated: 2023/11/14 23:17:04 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_found(char const c, char const *sep)
{
	size_t	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	while (ft_found(s1[i], set))
		i++;
	while (j && ft_found(s1[j - 1], set))
		j--;
	str = ft_substr(s1, i, j - i);
	return (str);
}
