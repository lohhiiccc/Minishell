/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:58:25 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 19:58:39 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include "expand_utils.h"
#include "libft.h"

char	**expand_cmd(char **cmd, t_env *env)
{
	size_t	i;
	char	*str;

	(void)env;
	i = 0;
	str = NULL;
	while (cmd[i])
	{
		if (0 != expand_str(cmd, i, env, str))
			return (NULL);
		str = ft_sprintf("%S%s ", str, cmd[i]);
		if (NULL == str)
			return (free_expand(cmd, i, str));
		free(cmd[i]);
		i++;
	}
	free(cmd);
	cmd = ft_split(str, " \t\n");
	free(str);
	if (NULL == cmd)
		return (NULL);
	cmd = expand_wildcard(cmd);
	if (NULL == cmd)
		return (NULL);
	i = 0;
	while (cmd[i])
		remove_quote(cmd[i++]);
	return (cmd);
}

