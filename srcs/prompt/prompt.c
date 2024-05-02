/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/05/02 01:42:36 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "minishell.h"
#include "exec.h"
#include "ft_printf.h"
#include "prompt.h"
#include "ms_signal.h"

static uint8_t	init_fd(t_fds *fd);
static uint8_t	free_fd(t_fds *fd, uint8_t ret);
static void		end_of_file(t_param *param);
static int		create_and_exec_tree(t_param *param,
					t_fds *fd, t_vector *tokens);

int	prompt(t_param *param)
{
	char		*str;
	t_vector	tokens;
	t_fds		fd;

	ms_signal_main();
	tokens.nbr_elem = 0;
	str = prompt_value(param);
	if (str == NULL)
		end_of_file(param);
	if (g_sig_value != 0)
	{
		free(str);
		param->ret = 128 + g_sig_value;
		return (128 + g_sig_value);
	}
	if (init_fd(&fd))
		return (1);
	if (-1 != lexer(str, &tokens, param)
		&& 1 == create_and_exec_tree(param, &fd, &tokens))
		return (1);
	if (str && str[0])
		manage_history(str);
	free(str);
	return (free_fd(&fd, 1));
}

static void	end_of_file(t_param *param)
{
	ft_printf("Exit\n");
	clear_env(&param->env);
	exit(param->ret);
}

static int	create_and_exec_tree(t_param *param, t_fds *fd, t_vector *tokens)
{
	t_tree	*tree;

	tree = parsing(param, tokens);
	if (tree == NULL)
		return (free_fd(fd, 1));
	if (param->ptree == 1)
		print_tree(tree);
	if (g_sig_value)
	{
		ft_clean_tree(tree);
		param->ret = g_sig_value + 128;
		return (128 + g_sig_value);
	}
	param->ret = exec_args(tree, fd, NULL, param);
	ft_clean_tree(tree);
	return (0);
}

static uint8_t	free_fd(t_fds *fd, uint8_t ret)
{
	ft_vector_free(&fd->fd_in, NULL);
	ft_vector_free(&fd->fd_out, NULL);
	return (ret);
}

static uint8_t	init_fd(t_fds *fd)
{
	if (-1 == ft_vector_init(&fd->fd_in, sizeof(int)))
	{
		write(2, "Minichell: malloc error\n", 25);
		return (1);
	}
	if (-1 == ft_vector_init(&fd->fd_out, sizeof(int)))
	{
		write(2, "Minichell: malloc error\n", 25);
		free(fd->fd_in.addr);
		return (1);
	}
	return (0);
}
