
#include <stdlib.h>
#include "expand.h"
#include "libft.h"

static int get_value(char *s, size_t *i, char **env, t_vector *vector);
int8_t expand_var(char **str, t_vector *env)
{
	char 	*s;
	size_t	i;
	t_vector new;

	if (-1 == ft_vector_init(&new, sizeof(char)))
		return (-1);
	i = 0;
	s = *str;
	while (s[i])
	{
		if (s[i] == '$' && is_charset(s[i + 1]))
		{
			i++;
			get_value(s, &i, ft_vector_get(env, 0), &new);
		}
		else
			if (-1 == ft_vector_add(&new, &s[i]))
				return (-1);
		if (s[i])
			i++;
	}
	free(s);
	*str = ft_vector_get(&new, 0);
	char c = '\0';
	return (ft_vector_add(&new, &c));
}

static int get_value(char *s, size_t *i, char **env, t_vector *vector)
{
	char *value;
	size_t	backup;

	backup = *i;
	value = env[get_envline(env, s + *i)];
	while (s[*i] && is_charset(s[*i]))
		(*i)++;
	--*i;
	if (value == NULL)
		return 0;
	value += (*i - backup + 2);
	return ft_vector_add_n(vector, value, ft_strlen(value));
}
