
#include "expand.h"

static int	searchvar(const char *s1, char *s2);

size_t	get_envline(char **env, char *var)
{
	size_t i;

	i = 0;
	while (env[i])
	{
		if (searchvar(var, env[i]))
			return i;
		i++;
	}
	return i;
}

static int	searchvar(const char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && is_charset(s1[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i] == '=')
		return (1);
	return (0);
}
