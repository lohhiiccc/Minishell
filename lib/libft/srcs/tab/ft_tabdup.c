/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:18:09 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/24 23:20:30 by mjuffard         ###   ########lyon.fr   */
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
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
