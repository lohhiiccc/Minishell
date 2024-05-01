/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:55:37 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 00:55:39 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

static char	value(char c);
static void	end_folder_mode(size_t *j, char *patern);

uint8_t	is_match(char *str, char *patern, size_t i, size_t j)
{
	while ((patern[j] && patern[j] == '*' && patern[j + 1] == '*')
		|| (patern[j] == '\'' || patern[j] == '"'))
		j++;
	end_folder_mode(&j, patern);
	if (value(patern[j]) && value(patern[j]) == '/' && !value(patern[j + 1]))
		return (1);
	if (!str[i] && !value(patern[j]))
		return (1);
	if (value(patern[j]) == '*')
		return (is_match(str, patern, i, j + 1)
			|| (str[i] && is_match(str, patern, i + 1, j)));
	if ((value(patern[j]) == '?' && str[i]) || value(patern[j]) == str[i])
		return (is_match(str, patern, i + 1, j + 1));
	return (0);
}

static void	end_folder_mode(size_t *j, char *patern)
{
	size_t	i;

	i = 0;
	while (value(patern[i + *j]) == '/')
		i++;
	if (patern[i + *j] == '\0')
		*j += i;
}

static char	value(char c)
{
	if (c < 0)
	{
		c = -c;
		if (c == '*' || c == '?' || c == '\'' || c == '"')
			c = -c;
		return (c);
	}
	return (c);
}
