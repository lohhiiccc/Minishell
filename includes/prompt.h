/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 22:22:55 by mjuffard          #+#    #+#             */
/*   Updated: 2024/05/02 01:47:57 by mjuffard         ###   ########lyon.fr   */

/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

	
# define E_CHICKEN "\001\xF0\x9F\002\x90\x94"
# define E_EGG "\001\xF0\x9F\002\xA5\x9A"
# define E_EGG2 "\001\xF0\x9F\002\x90\xA5"
# define RED "\001\e[31m\002"
# define UNDERLINE "\001\e[4m\002"
# define GREEN "\001\e[92m\002"
# define END "\001\e[0m\002"
# define YELLOW "\001\e[33m\002"
# define LIGHTGREEN "\001\e[32m\002"
# define PROMPTSKIN "%s[%s]%s[%s] %s%sMinichel%s%s$%s "
# define HEREDOCSKIN "%s[%s]%sle croquant: %s[%s%s%s%s%s]%s> "

void	manage_history(char *str);
char	*prompt_value(t_param *param);
void	prompt_back_slash(char *s);

#endif