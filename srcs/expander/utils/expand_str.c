
#include "expand_utils.h"

static uint8_t have_wildcard(char *str);
int8_t expand_str(char **str, size_t i, t_env *env, char *error)
{
	set_snegative(str[i]);
	if (-1 == expand_ret(&str[i], env->ret)
		|| -1 == expand_var(&str[i], &env->env))
	{
		free_expand(str, i , error);
		return (-1);
	}
	set_negative(str[i]);
	if (have_wildcard(str[i]))
	{
		if (-1 == wildcard(str[i], &str[i]))
			return (-1);
	}
	return (0);
}

static uint8_t have_wildcard(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*' || str[i] == '?')
			return (1);
		i++;
	}
	return (0);
}