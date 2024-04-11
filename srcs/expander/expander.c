#include "ft_printf.h"
#include <stdlib.h>
#include "expand.h"
#include "libft.h"

static	void *free_expand(char **str, size_t i, char *error);
static int8_t expand_str(char **str, size_t i, t_env *env, char *error);
//$PWD$PWD didn't work
char **expand_cmd(char **cmd, t_env *env)
{
	size_t		i;
	char		*str;

	i = 0;
	str = NULL;
	while (cmd[i])
	{
		if (0 != expand_str(cmd, i, env, str))
			return (NULL);
		str = ft_sprintf("%S%s ", str, cmd[i]);
		if (NULL == str)
			return (free_expand(cmd, i ,str));
		free(cmd[i]);
		i++;
	}
	free(cmd);
	cmd = ft_split(str, " \t\n");
	free(str);
	if (NULL == cmd)
		return (NULL);
	i = 0;
	while (cmd[i])
		remove_quote(cmd[i++]);
	return (cmd);
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

static int8_t expand_str(char **str, size_t i, t_env *env, char *error)
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