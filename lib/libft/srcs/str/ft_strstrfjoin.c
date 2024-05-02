/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrfjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:32:34 by lrio              #+#    #+#             */
/*   Updated: 2024/05/02 04:25:56 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrfjoin(char *str1, char *str2, char *str3)
{
	char	*buffer;
	char	*res;

	buffer = ft_strjoin(str1, str2);
	if (!buffer)
		return (NULL);
	res = ft_strfjoin(buffer, str3);
	if (!res)
		return (NULL);
	return (res);
}
