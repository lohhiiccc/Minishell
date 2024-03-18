/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:50 by lrio              #+#    #+#             */
/*   Updated: 2024/03/17 16:25:31 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	size_t			width;
	char			*cpy;

	if (!src)
		return (ft_calloc(1, sizeof(char)));
	width = ft_strlen(src) + 1;
	cpy = malloc((sizeof(char) * width));
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, (char *)src, width);
	return ((char *)cpy);
}
