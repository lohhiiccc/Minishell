/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:42:13 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/07 21:52:02 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <unistd.h>

void	close_vector_fd(t_vector *fd)
{
	size_t	i;

	i = 0;
	while (i < fd->nbr_elem)
	{
		close(*(int *)ft_vector_get(fd, i));
		i++;
	}
}

int	is_build_in(char *str)
{
	if (NULL == str)
		return (0);
	if (!ft_strcmp(str, "cd"))
		return (1);
	if (!ft_strcmp(str, "echo"))
		return (1);
	if (!ft_strcmp(str, "param"))
		return (1);
	if (!ft_strcmp(str, "exit"))
		return (1);
	if (!ft_strcmp(str, "export"))
		return (1);
	if (!ft_strcmp(str, "pwd"))
		return (1);
	if (!ft_strcmp(str, "unset"))
		return (1);
	if (!ft_strcmp(str, "return"))
		return (1);
	if (!ft_strcmp(str, "ptree"))
		return (1);
	return (0);
}
