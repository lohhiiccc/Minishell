/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:35:59 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/29 03:01:08 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "ft_printf.h"
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

int	exec_here_doc(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	fd;
	int	ret;

	fd = open((char *)tree->structur, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	unlink((char *)tree->structur);
	ft_vector_add(fd_in, &fd);
	ret = exec_args(tree->left, fd_in, fd_out, tree->root);
	ft_vector_delete_elem(fd_in, fd_in->nbr_elem);
	if (close(fd) == -1)
	{
		ft_dprintf(2, "Minichell: %s: %s\n",
			(char *)tree->structur, strerror(errno));
		return (1);
	}
	return (ret);
}

int	create_file_here_doc(t_tree *tree)
{
	char	*file_name;
	char	*str;
	int		fd;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (1);
	file_name = malloc(sizeof(char) * 7);
	if (!file_name)
		return (1);
	if (read(fd, file_name, 6) == -1)
		return (1);
	file_name[6] = 0;
	while (access(file_name, F_OK))
	{
		free(file_name);
		file_name = malloc(sizeof(char) * 7);
		if (!file_name)
			return (1);
		if (read(fd, file_name, 6) == -1)
			return (1);
		file_name[6] = 0;
	}
	close(fd);
	fd = open(file_name, O_RDWR | O_CREAT, 0777);
	if (fd == -1)
		return (1);
	str = readline("Le croquant > ");
	while (ft_strcmp(str, (char *)tree->structur))
	{
		if (write(fd, str, ft_strlen(str)) == -1)
			return (1);
		if (write(fd, "\n", 1) == -1)
			return (1);
		free(str);
		str = readline("Le croquant > ");
	}
	free(str);
	free(tree->structur);
	close(fd);
	tree->structur = file_name;
	return (0);
}
