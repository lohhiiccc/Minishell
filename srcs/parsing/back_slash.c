/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_slash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:56:32 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 00:56:35 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	prompt_back_slash(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\\')
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			s[i] = -s[i];
		}
		i++;
	}
}

void	heredoc_back_slash(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\\' && s[i + 1] == '\0')
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			s[i] = 127;
		}
		else if (s[i] == '\\' && (s[i + 1] == '$'
				|| s[i + 1] == '\\' || s[i] == '\n'))
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			s[i] = -s[i];
		}
		i++;
	}
}
