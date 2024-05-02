/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_here_doc_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:55:56 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 04:13:08 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>

#include "expand.h"
#include "tree.h"
#include "ft_printf.h"
#include "libft.h"
#include "expand_utils.h"

static char		*get_file_name(void);
static int		fill_heredoc(t_tree *tree, int fd, t_param *param);
static int8_t	expand_heredoc(char **s, t_param *param, size_t i);

int	create_file_here_doc(t_tree *tree, t_param *param)
{
	char	*file_name;
	int		fd;

	file_name = get_file_name();
	if (NULL == file_name)
		return (-1);
	fd = open(file_name, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		return (-1);
	if (fill_heredoc(tree, fd, param) == -1)
	{
		ft_free_tab(tree->structur);
		free(tree->structur);
		free(file_name);
		close(fd);
		return (-1);
	}
	ft_free_tab(tree->structur);
	tree->structur = NULL;
	close(fd);
	fd = open(file_name, O_RDWR, 0644);
	unlink(file_name);
	free(file_name);
	return (fd);
}

static int	fill_heredoc(t_tree *tree, int fd, t_param *param)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (((char **)tree->structur)[i])
	{
		if (expand_heredoc(((char **)tree->structur), param, i) == -1)
			return (-1);
		i++;
	}
	if (tree->structur == NULL)
		return (-1);
	i = 0;
	while (((char **)tree->structur)[i])
	{
		len = ft_strlen(((char **)tree->structur)[i]);
		if (len != 0)
			len -= 1;
		if (((char **)tree->structur)[i][len] == 127)
			ft_dprintf(fd, "%e", ((char **)tree->structur)[i]);
		else
			ft_dprintf(fd, "%s\n", ((char **)tree->structur)[i]);
		i++;
	}
	return (0);
}

static char	*get_file_name(void)
{
	int		fd;
	char	*file_name;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_name = malloc(sizeof(char) * 7);
	if (!file_name)
		return (NULL);
	if (read(fd, file_name, 6) == -1)
		return (NULL);
	file_name[6] = 0;
	close(fd);
	return (file_name);
}

static int8_t	expand_heredoc(char **s, t_param *param, size_t i)
{
	size_t	j;

	j = 0;
	if (expand_ret(&s[i], param->ret) == -1
		|| expand_var(&s[i], &param->env) == -1)
	{
		ft_free_tab(s);
		s = NULL;
		return (-1);
	}
	while (s[i][j])
	{
		if (s[i][j] < 0)
			s[i][j] = -s[i][j];
		j++;
	}
	return (0);
}
