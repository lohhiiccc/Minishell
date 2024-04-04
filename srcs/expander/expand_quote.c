
#include <stdlib.h>
#include "vector.h"
#include "expand.h"
#include "env.h"
#include "libft.h"

static int8_t is_inquote(char *s, t_vector *new, size_t *i, t_vector *env);
size_t	get_envline(char **env, char *var);
int get_value(char *s, size_t *i, char **env, t_vector *vector);
int8_t expand_quote(char **str, uint8_t *quote, t_vector *env)
{
	size_t	i;
	t_vector	new;
	char 		*s;

	s = str[0];
	if (-1 == ft_vector_init(&new, sizeof(char)))
		return -1;
	i = 0;
	while (s[i])
	{
		fill_quote(quote, s[i]);
		if (quote[1])
		{
			if (is_inquote(s, &new, &i, env))
				return (-1);
		}
		else if (-1 == ft_vector_add(&new, &s[i]))
			return (-1);
		i++;
	}
	if (-1 == ft_vector_add(&new, &s[i]))
		return (-1);
	free(*str);
	*str = ft_vector_get(&new, 0);
	ft_vector_print_str(&new);
	return (0);
}

static int8_t is_inquote(char *s, t_vector *new, size_t *i, t_vector *env)
{
	if (s[*i] != '$' || (s[*i] == '$' && !is_charset(s[*i + 1])))
	{
		if (-1 == ft_vector_add(new, &s[*i]))
			return (-1);
	}
	else
	{
		++*i;
		get_value(s, i, ft_vector_get(env, 0), new);
	}

	return (0);
}

int get_value(char *s, size_t *i, char **env, t_vector *vector)
{
	(void)s;
	(void)i;
	(void)env;
	(void)vector;
	while (s[*i] && is_charset(s[*i]))
		(*i)++;
	--*i;

	return 0;
}

size_t	get_envline(char **env, char *var)
{
	size_t i;

	i = 0;
	while (env[i])
	{
		if (0 == ft_strcmp(var, env[i]))
			return i;
		i++;
	}
	return i;
}