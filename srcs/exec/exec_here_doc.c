/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:35:59 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/24 02:52:57 by mjuffard         ###   ########lyon.fr   */
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

int	exec_here_doc(t_tree *tree, t_fds *fds, t_env *env)
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
	ft_vector_add(&fds->fd_in, &fd);
	ret = exec_args(tree->left, fds, tree->root, env);
	ft_vector_delete_elem(&fds->fd_in, fds->fd_in.nbr_elem);
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
		return (2);
	if (read(fd, file_name, 6) == -1)
		return (3);
	file_name[6] = 0;
//	while (access(file_name, F_OK))
//	{
//		free(file_name);
//		file_name = malloc(sizeof(char) * 7);
//		if (!file_name)
//			return (1);
//		if (read(fd, file_name, 6) == -1)
//			return (1);
//		file_name[6] = 0;
//	}
	close(fd);
	fd = open(file_name, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		return (6);
	str = readline("Le croquant > ");
	while (str && ft_strcmp(str, (char *)tree->structur))
	{
		if (write(fd, str, ft_strlen(str)) == -1)
			return (7);
		if (write(fd, "\n", 1) == -1)
			return (8);
		free(str);
		str = readline("Le croquant > ");
	}
	if (!str)
		ft_dprintf(2, "Minichell: warning: here-document\
delimited by end-of-file (wanted '%s')\n", (char *)tree->structur);
	free(str);
	free(tree->structur);
	close(fd);
	tree->structur = file_name;
	return (0);
}
