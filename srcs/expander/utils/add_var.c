

#include "expand.h"
#include "libft.h"

static int8_t	get_value(char *s, size_t i, char **env, t_vector *vector);

int8_t add_var(char *s, size_t *i, t_vector *env, t_vector *vector)
{
	if (-1 == get_value(s, *i + 1, ft_vector_get(env, 0), vector))
		return (-1);
	++*i;
	while (s[*i] && is_charset(s[*i]))
		++*i;
	return (0);
}

static int8_t	get_value(char *s, size_t i, char **env, t_vector *vector)
{
	char	*value;
	size_t	backup;

	backup = i;
	value = env[get_envline(env, s + i)];
	while (s[i] && is_charset(s[i]))
		i++;
	--i;
	if (value == NULL)
		return (0);
	value += (i - backup + 2);
	return (ft_vector_add_n(vector, value, ft_strlen(value)));
}
