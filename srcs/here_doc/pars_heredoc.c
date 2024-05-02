/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:56:05 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 04:13:21 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "tree.h"
#include "ft_printf.h"
#include "heredoc.h"
#include "ms_signal.h"

static int8_t	error(char *str, t_vector *v);

int	read_here_doc(t_tree *tree, size_t need_expand)
{
	t_vector	content;
	char		*buffer;

	if (ft_vector_init(&content, sizeof(char *)) == -1)
		return (-1);
	g_sig_value = 0;
	buffer = here_doc_rl((char *) tree->structur, need_expand);
	while (!g_sig_value && buffer && ft_strcmp(buffer, (char *)tree->structur))
	{
		if (ft_vector_add_ptr(&content, buffer) == -1)
			return (error(buffer, &content));
		buffer = here_doc_rl((char *) tree->structur, need_expand);
	}
	if (!buffer)
		ft_dprintf(STDERR_FILENO, HERE_DOC_EOF, ((char *)tree->structur));
	else if (g_sig_value)
		free(buffer);
	if (ft_vector_add_ptr(&content, NULL) == -1)
		return (error(buffer, &content));
	free(tree->structur);
	tree->structur = ft_vector_get(&content, 0);
	return (g_sig_value);
}

static int8_t	error(char *str, t_vector *v)
{
	ft_vector_free(v, free);
	free(str);
	return (-1);
}
