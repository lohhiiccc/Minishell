/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:37:19 by lrio              #+#    #+#             */
/*   Updated: 2024/03/01 14:47:52 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_echo(char **arg)
{
	size_t	i;

	i = 1;
	if (arg[i] && !ft_strcmp(arg[i], "-n"))
		i++;
	while (arg[i])
	{
		ft_putstr_fd(arg[i], 1);
		i++;
	}
	if (ft_strcmp(arg[1] && !arg[1], "-n"))
		return (0);
	write(1, "\n", 1);
	return (0);
}
