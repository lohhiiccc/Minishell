/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:01:24 by mjuffard          #+#    #+#             */
/*   Updated: 2024/01/09 03:23:06 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *rest, size_t n)
{
	char	*ret;
	int		check_rd;

	ret = NULL;
	check_rd = 1;
	while (n == 0 && check_rd > 0)
	{
		ret = ft_strnjoin(ret, rest, n);
		rest[0] = 0;
		if (!ret)
			return (NULL);
		check_rd = read(fd, rest, BUFFER_SIZE);
		if (check_rd == -1)
			return (ft_clean(ret, rest));
		rest[check_rd] = 0;
		n = ft_nxtln(rest);
	}
	if (n)
	{
		ret = ft_strnjoin(ret, rest, n);
		if (!ret)
			return (NULL);
		ft_memmove(rest, n);
	}
	return (ret);
}

char	*ft_build_line(int fd)
{
	static char	rest[FD_MAX][BUFFER_SIZE + 1] = {0};
	char		*ret;
	size_t		nxt_line;

	ret = NULL;
	nxt_line = ft_nxtln(rest[fd]);
	if (nxt_line)
	{
		ret = ft_strnjoin(ret, rest[fd], nxt_line);
		if (!ret)
			return (NULL);
		ft_memmove(rest[fd], nxt_line);
		return (ret);
	}
	else
	{
		ret = ft_read(fd, rest[fd], nxt_line);
		if (!ret)
			return (NULL);
	}
	if (ret && !ret[0])
		return (ft_clean(ret, rest[fd]));
	return (ret);
}

char	*get_next_line(int fd)
{
	if (BUFFER_SIZE > 2147479552 || BUFFER_SIZE < 1 || fd < 0 || fd >= FD_MAX)
		return (NULL);
	return (ft_build_line(fd));
}
