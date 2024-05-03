/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:58:25 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 04:26:24 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_printf.h"
#include "expand_utils.h"
#include "libft.h"

char	**word_split(char **cmd, size_t i, char *str);

char	**expand_cmd(char **cmd, t_param *param)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	while (cmd[i])
	{
		if (0 != expand_str(cmd, i, param, str))
			return (NULL);
		str = ft_sprintf("%S%s ", str, cmd[i]);
		if (!str)
			return (free_expand(cmd, i, str));
		free(cmd[i]);
		i++;
	}
	free(cmd);
	return (word_split(cmd, i, str));
}

char	**word_split(char **cmd, size_t i, char *str)
{
	if (cmd == NULL)
		return (cmd);
	cmd = ft_split(str, " \t\n");
	free(str);
	if (cmd == NULL || *cmd == NULL)
		return (cmd);
	cmd = expand_wildcard(cmd);
	if (cmd == NULL)
		return (NULL);
	i = 0;
	while (cmd[i])
		remove_quote(cmd[i++]);
	return (cmd);
}
