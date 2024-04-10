
#include <stdlib.h>
#include "expand.h"
#include "libft.h"

static int get_value(char *s, size_t i, char **env, t_vector *vector);
int8_t expand_var(char **str, t_vector *env)
{
	char *s;
	t_vector new;
	size_t	i;
	int8_t ret;

	if (-1 == ft_vector_init(&new, sizeof(char)))
		return (-1);
	s = *str;
	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && is_charset(s[i + 1]))
		{
			if (-1 == get_value(s, i+1, ft_vector_get(env, 0), &new))
				return (-1);
			i++;
			while (s[i] && is_charset(s[i]))
				i++;
		}
		if (-1 == ft_vector_add(&new, &s[i]))
			return (-1);
		if (s[i])
			i++;
	}
	ret = ft_vector_add(&new, &s[i]);
	*str = ft_vector_get(&new, 0);
	return (ret);
}

static int get_value(char *s, size_t i, char **env, t_vector *vector)
{
	char *value;
	size_t	backup;

	backup = i;
	value = env[get_envline(env, s + i)];
	while (s[i] && is_charset(s[i]))
		(i)++;
	--i;
	if (value == NULL)
		return 0;
	value += (i - backup + 2);
	return ft_vector_add_n(vector, value, ft_strlen(value));
}
