/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 20:01:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/17 20:01:56 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*free_expand(char **str, size_t i, char *error)
{
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	free(error);
	return (NULL);
}
