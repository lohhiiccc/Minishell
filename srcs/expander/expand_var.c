
#include "expand.h"
#include "libft.h"

static int8_t get_value(char *s, size_t i, char **env, t_vector *vector);
static int8_t free_and_return(t_vector *v);
static int8_t add_var(char *s, size_t *i, t_vector *env, t_vector *vector);

int8_t expand_var(char **str, t_vector *env)
{
	char		*s;
	t_vector	new;
	size_t		i;

	if (-1 == ft_vector_init(&new, sizeof(char)))
		return (-1);
	s = *str;
	i = 0;
	while (s[i])
	{
		if (s[i] == '$' && (ft_isalpha(s[i + 1]) || s[i + 1] == '_'))
		{
			if (-1 == add_var(s, &i, env, &new))
				return (free_and_return(&new));
			continue;
		}
		if (-1 == ft_vector_add(&new, &s[i]))
			return (free_and_return(&new));
		if (s[i])
			i++;
	}
	if (-1 == ft_vector_add(&new, &s[i]))
		return (free_and_return(&new));
	*str = ft_vector_get(&new, 0);
	return (0);
}

static int8_t add_var(char *s, size_t *i, t_vector *env, t_vector *vector)
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

static int8_t free_and_return(t_vector *v)
{
	ft_vector_free(v, NULL);
	return (-1);
}