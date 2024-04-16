
#include <stdlib.h>
#include "expand.h"

static	void *free_expand(char **str, size_t i, char *error);

int8_t expand_str(char **str, size_t i, t_env *env, char *error)
{
	set_snegative(str[i]);
	if (-1 == expand_ret(&str[i], env->ret)
		|| -1 == expand_var(&str[i], &env->env))
	{
		free_expand(str, i , error);
		return (-1);
	}
	set_negative(str[i], '"');
	return (0);
}

static	void *free_expand(char **str, size_t i, char *error)
{
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	free(error);
	return (NULL);
}
