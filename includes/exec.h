/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 00:18:06 by mjuffard          #+#    #+#             */
/*   Updated: 2024/02/21 03:52:04 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

#include <stdbool.h>

enum e_operator
{
	OR,
	AND,
	PIPE,
	HERE_DOC,
	APPEND,
	OUTPUT,
	INPUT
};

typedef struct s_type
{
	bool	type;
	void	*structure;
}	t_type;

typedef struct s_cmd
{
	char	*path;
	char	**arg;
}	t_cmd;

typedef struct s_ope
{
	enum e_operator	type;
	char			*file;
}	t_ope;

#endif