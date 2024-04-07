/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:36:34 by lrio              #+#    #+#             */
/*   Updated: 2024/04/07 23:15:30 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "libft.h"
#include "ft_printf.h"
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "build_in.h"

int	ft_cd(t_cmd *cmd)
{
	char	*str;
	char	**tab;
	char	*temp;

	tab = malloc(sizeof(char *) * 3);
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
			free(str);
			ft_dprintf(2, "Minichel: cd: %s: %s\n", cmd->arg[1],
				strerror(errno));
			return (1);
		}
		free(str);
		tab[0] = NULL;
		tab[1] = ft_sprintf("PWD=%s", getcwd(NULL, 0));
		tab[2] = NULL;
		ft_export(tab, &cmd->env->env);
		ft_free_tab(tab);
		return (0);
	}
	return (0);
}
