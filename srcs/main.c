/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 01:46:37 by lrio              #+#    #+#             */
/*   Updated: 2024/04/25 18:10:31 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <unistd.h>

#include "ms_signal.h"
#include "minishell.h"
#include "ft_printf.h"

int	main(int argc, char **argv, char **env)
{
	t_env		new_env;

	(void)argc;
	(void)argv;
	rl_event_hook = &do_nothing;
	new_env.ret = 0;
	new_env.ptree = -1;
	new_env.is_main = 0;
	if (!isatty(0) || !isatty(1))
	{
		ft_dprintf(STDERR_FILENO, "minichel: please use a tty\n");
		return (1);
	}
	if (-1 == init_env(env, &new_env.env))
		return (1);
	while (prompt(&new_env))
		;
	return (127);
}
