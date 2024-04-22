/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:46:37 by lrio              #+#    #+#             */
/*   Updated: 2024/04/17 16:13:02 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ms_signal.h"
#include "minishell.h"
#include "ft_printf.h"
#include <unistd.h>

int	main(int argc, char **argv, char **env)
{
	t_env		new_env;

	(void)argc;
	(void)argv;
	new_env.ret = 0;
	new_env.ptree = -1;
	ms_signal();
	if (!isatty(0) || !isatty(1))
	{
		ft_dprintf(2, "minichel: please use a tty\n");
		return (1);
	}
	if (-1 == init_env(env, &new_env.env))
		return (1);
	while (prompt(&new_env))
		;
	return (127);
}
