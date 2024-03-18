/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:12:37 by lrio              #+#    #+#             */
/*   Updated: 2024/03/17 16:27:01 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *src, size_t n)
{
	size_t			width;
	char			*cpy;

	if (!src)
		return (ft_calloc(1, sizeof(char)));
	width = ft_strlen(src) + 1;
	if (width > n)
		width = n + 1;
	cpy = malloc((sizeof(char) * width));
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, (char *)src, width);
	return ((char *)cpy);
}
