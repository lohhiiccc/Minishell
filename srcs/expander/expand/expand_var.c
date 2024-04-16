
#include "expand.h"
#include "libft.h"

static int8_t free_and_return(t_vector *v);

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

static int8_t free_and_return(t_vector *v)
{
	ft_vector_free(v, NULL);
	return (-1);
}