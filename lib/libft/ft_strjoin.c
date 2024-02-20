/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:00:51 by mjuffard          #+#    #+#             */
/*   Updated: 2023/11/13 13:36:06 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	ret = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ret)
		return (0);
	while (i < ft_strlen(s1))
	{
		ret[i] = s1[i];
		i++;
	}
	while (i + j < ft_strlen(s1) + ft_strlen(s2))
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = 0;
	return (ret);
}
