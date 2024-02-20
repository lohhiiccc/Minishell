/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:49:18 by lrio              #+#    #+#             */
/*   Updated: 2024/01/22 12:52:08 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(const char *src, int c)
{
	size_t			width;
	char			*cpy;

	width = ft_strclen(src, c) + 1;
	cpy = malloc((sizeof(char) * width));
	if (!cpy)
		return (0);
	ft_strlcpy(cpy, (char *)src, width);
	return ((char *)cpy);
}
