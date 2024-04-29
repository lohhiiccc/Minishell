/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:18:09 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/25 03:52:09 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabdup(char **tab)
{
	size_t	len;
	size_t	i;
	char	**ret;

	len = ft_tablen(tab);
	i = 0;
	ret = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		ret[i] = ft_strdup(tab[i]);
		if (!ret[i])
		{
			while (i > 0)
			{
				free(ret[i]);
				i--;
			}
			free(ret[i]);
			free(ret);
			return (NULL);
		}
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
