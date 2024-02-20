/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:56:58 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/09 03:22:29 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_nxtln(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_clean(char *str1, char *str2)
{
	free(str1);
	str2[0] = 0;
	str1 = NULL;
	return (NULL);
}

void	ft_memmove(char *rest, size_t n)
{
	size_t	i;

	i = 0;
	while (rest[i + n])
	{
		rest[i] = rest[i + n];
		i++;
	}
	rest[i] = 0;
}

char	*ft_strnjoin(char *str1, char *str2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	j = 0;
	if (n == 0)
		n = ft_strlen(str2);
	temp = malloc((ft_strlen(str1) + n) * sizeof(char) + 1);
	if (!temp)
		return (ft_clean(str1, str2));
	while (str1 && str1[i])
	{
		temp[i] = str1[i];
		i++;
	}
	while (str2 && j < n)
	{
		temp[i + j] = str2[j];
		j++;
	}
	temp[i + j] = 0;
	free(str1);
	return (temp);
}
