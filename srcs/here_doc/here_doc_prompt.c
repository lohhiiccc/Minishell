/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 00:56:01 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 01:30:35 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <stdlib.h>

#include "ft_printf.h"
#include "heredoc.h"
#include "libft.h"
#include "prompt.h"

void	escape_str(char *str);

char	*here_doc_rl(char *del, size_t need_expand)
{
	char	*str;
	char	*buffer;

	buffer = ft_sprintf(HEREDOCSKIN,
			GREEN, E_CHICKEN, END, GREEN,
			LIGHTGREEN, UNDERLINE, del, END, GREEN, END);
	if (buffer != NULL)
	{
		str = readline(buffer);
		free(buffer);
	}
	else
		str = readline("le croquant [unknow]> ");
	heredoc_back_slash(str);
	if (str && ft_strcmp(str, del) == 0)
		return (del);
	if (need_expand != 0)
		escape_str(str);
	return (str);
}

void	escape_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 0)
			str[i] = -str[i];
		i++;
	}
}
