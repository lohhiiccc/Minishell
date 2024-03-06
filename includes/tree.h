/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:17:06 by lrio              #+#    #+#             */
/*   Updated: 2024/03/07 00:15:29 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:43:43 by lrio              #+#    #+#             */
/*   Updated: 2024/03/04 18:20:50 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef enum	e_node
{
	O_OR,		// ||
	O_AND,		// &&
	O_PIPE,		// |
	HERE_DOC,	// <<
	APPEND,		// >>
	OUTPUT,		// >
	INPUT,		// <
	CMD,
}	t_node;

typedef struct s_tree
{
	struct s_tree	*left;
	struct s_tree	*right;
	enum e_node		type;
	void			*structur;
}	t_tree;

typedef struct s_cmd
{
	char	*path;
	char	**arg;
	char	**env;
}	t_cmd;

t_tree	*ft_join_tree(t_tree *left, t_tree *right, void *content, t_node node);
void	ft_clean_tree(t_tree *tree);
t_tree	*ft_new_tree(void *content, t_node node);

#endif