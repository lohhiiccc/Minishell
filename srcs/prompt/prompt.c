/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:29:59 by lrio              #+#    #+#             */
/*   Updated: 2024/03/11 19:06:55 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "make_tree.h"

static void	print_token(t_vector *tokens)
{
	(void)tokens;
//	for (size_t i = 0; i < tokens->nbr_elem; ++i) {
		;//printf("\n%zu: %d\t|%s\n", i , ((t_token *)tokens->addr)[i].type, ((t_token *)tokens->addr)[i].str);
//	}
}

t_tree *prompt(char **env)
{
	char *str;
	t_vector tokens;
	t_tree 	*tree;

	tokens.nbr_elem = 0;
	str = readline("minichel>");
	if (!str)
		return (NULL);
	if (-1 != lexer(str, &tokens))
	{
		tree = make_sub(ft_vector_get(&tokens, 0), env);
		print_tree(tree);
	}
	if (str && str[0])
	{
		add_history(str);
		print_token(&tokens);
	}
	free_token(&tokens);
	free(str);
	return (tree);
}
