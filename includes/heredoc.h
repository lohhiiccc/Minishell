/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:51:31 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/01 00:51:34 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "tree.h"

# define HERE_DOC_EOF \
	"Minichell: warning: here-document delimited by end-of-file (wanted `%s')\n"

int		create_file_here_doc(t_tree *tree, t_param *param);
char	*here_doc_rl(char *del, size_t need_expand);
void	heredoc_back_slash(char *s);
int		read_here_doc(t_tree *tree, size_t need_expand);

#endif