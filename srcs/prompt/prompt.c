/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrio <lrio@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/02/21 03:32:29 by lrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <readline/readline.h>
#include <stdio.h>
#include <readline/history.h>
#include <stdlib.h>

void prompt(void)
{
	char *str;

	while (1)
	{
		str = readline("minichel>");
		if (str)
			add_history(str);
		free(str);
	}
}
