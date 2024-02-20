/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:35:50 by lrio              #+#    #+#             */
/*   Updated: 2024/01/26 14:34:20 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
