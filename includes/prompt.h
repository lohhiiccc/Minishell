/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:22:55 by mjuffard          #+#    #+#             */
/*   Updated: 2024/04/19 18:29:15 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

# define E_EGG "\001\xF0\x9F\002\xA5\x9A"
# define E_EGG2 "\001\xF0\x9F\002\x90\xA5"
# define RED "\001\e[31m\002"
# define UNDERLINE "\001\e[4m\002"
# define CYAN "\001\e[0;96m\002"
# define GREEN "\001\e[92m\002"
# define END "\001\e[0m\002"
# define YELLOW "\001\e[33m\002"
# define LIGHTGREEN "\001\e[32m\002"
# define PROMPTSKIN "%s[%s]%s[%s] %s%sMinichell%s%s$%s "

void	manage_history(char *str);
char	*prompt_value(int last_ret);

#endif