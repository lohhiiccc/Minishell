/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_skin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:16:29 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 01:49:47 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "prompt.h"
#include "ft_printf.h"
#include "libft.h"

char	*prompt_value(t_param *param)
{
	char	*prompt;
	char	*pwd;
	char	*line;
	char	*term_value;

	pwd = getcwd(NULL, 0);
	term_value = found_value_of_variable("TERM", param->env);
	if (!term_value || ft_strcmp(term_value, "xterm-256color"))
		prompt = NULL;
	else if (param->ret != 0)
		prompt = ft_sprintf(PROMPTSKIN, RED, E_EGG2, END, pwd, UNDERLINE,
				RED, END, YELLOW, END);
	else
		prompt = ft_sprintf(PROMPTSKIN, GREEN, E_EGG, END, pwd, UNDERLINE,
				LIGHTGREEN, END, YELLOW, END);
	free(pwd);
	free(term_value);
	if (!prompt)
	{
		line = readline("[x] [error] Minichel$ ");
		return (line);
	}
	line = readline(prompt);
	free(prompt);
	return (line);
}
