/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 03:01:13 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/04 20:01:41 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include <stdlib.h>
#include <readline/readline.h>

void	clean_exit(t_tree *tree, t_vector *fd_in, t_vector *fd_out,
	uint8_t status)
{
	rl_clear_history();
	ft_clean_tree(tree);
	close_vector_fd(fd_in);
	close_vector_fd(fd_out);
	ft_vector_free(fd_in, NULL);
	ft_vector_free(fd_out, NULL);
	exit(status);
}
