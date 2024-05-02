/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:55:41 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 04:26:41 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "expand_utils.h"
#include "libft.h"

int8_t	wildcard(char *patern, char **wildcard)
{
	DIR				*directory;
	struct dirent	*dir_data;
	char			**folder;
	uint8_t			is_folder;

	dir_data = NULL;
	directory = opendir(".");
	if (directory == NULL)
		return (-1);
	is_folder = patern[ft_strlen(patern) - 1] == '/';
	folder = get_folder(directory, &dir_data, (patern[0] == '.'), is_folder);
	closedir(directory);
	if (!folder)
		return (-1);
	return (fill_wildecard(patern, folder, wildcard, is_folder));
}
