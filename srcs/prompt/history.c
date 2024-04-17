/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:01:55 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 22:01:57 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static long long	get_id(const char *str);

void	manage_history(char *str)
{
	static long long	id = 0;
	long long			tmp;

	tmp = get_id(str);
	if (tmp == id)
		return ;
	id = tmp;
	add_history(str);
}

static long long	get_id(const char *str)
{
	size_t		i;
	char		j;
	long long	id;

	id = 5381;
	i = 0;
	while (str[i])
	{
		j = str[i];
		id = ((id << 5) + id) + j;
		i++;
	}
	return (id);
}
