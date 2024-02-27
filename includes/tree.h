/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:34:40 by lrio              #+#    #+#             */
/*   Updated: 2024/02/27 17:41:03 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef enum e_operator
{
	OR,			// ||
	AND,		// &&
	PIPE,		// |
}	t_operator;

typedef enum e_redirect
{
	HERE_DOC,	// <<
	APPEND,		// >>
	OUTPUT,		// >
	INPUT,		// <
}	t_redirect;

enum	e_node
{
	REDIRECT,
	CMD,
	OPE,
};

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
	int		fd_in;
	int		fd_out;
}	t_cmd;

typedef struct s_red
{
	enum e_redirect	type;
	char			*file;
}	t_red;

t_tree	*ft_join_tree(t_tree *left, t_tree *right, void *content);
void	ft_clean_tree(t_tree *tree);
t_tree	*ft_new_tree(void *content);

#endif