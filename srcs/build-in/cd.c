/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:34 by lrio              #+#    #+#             */
/*   Updated: 2024/03/29 09:59:20 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int	ft_cd(t_cmd *cmd)
{
	char	*str;
	char	*temp;

	if (cmd->arg[2])
	{
		ft_dprintf(2, "Minichel: cd: too many argument\n");
		return (1);
	}
	if (cmd->arg[1])
	{
		temp = getcwd(NULL, 0);
		if (!temp)
			return (1);
		str = ft_sprintf("%s/%s", temp, cmd->arg[1]);
		free(temp);
		if (!str)
			return (1);
		if (chdir(str) == -1)
		{
			ft_dprintf(2, "Minichel: cd: %s: %s\n", cmd->arg[1],
				strerror(errno));
			return (1);
		}
		return (0);
	}
	return (0);
}
