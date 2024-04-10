
#include <stdlib.h>
#include "vector.h"
#include "expand.h"
#include "libft.h"
#include "ft_printf.h"

static void	set_negative(char *str, char c);
static void	set_snegative(char *str);

char **expand_cmd(char **cmd, t_env *env)
{
	uint8_t		quotes[2];
	size_t		i;
	char		*str;

	i = 0;
	str = NULL;
	ft_bzero(quotes, sizeof(uint8_t) * 2);
	while (cmd[i])
	{
		set_snegative(cmd[i]);
		expand_ret(&cmd[i], env->ret);
		expand_var(&cmd[i], &env->env);
		set_negative(cmd[i], '"');
		str = ft_sprintf("%S%s ", str, cmd[i]);
		i++;
	}
	ft_free_tab(cmd);
	cmd = ft_split(str, " \t\n");
	free(str);
	if (NULL == cmd)
		return (NULL);
	i = 0;
	while (cmd[i])
		remove_quote(cmd[i++]);
	return (cmd);
}

static void	set_snegative(char *str)
{
	size_t	i;
	const char c = '\'';

	i = 0;
	while (str[i]) {
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
				i++;
		}
		if (str[i] == c)
		{
			i++;
			while (str[i] != c && str[i])
			{
				str[i] = -str[i];
				i++;
			}
		}
		if (str[i])
			i++;
	}
}

static void	set_negative(char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
			while (str[i] != c && str[i])
			{
				str[i] = -str[i];
				i++;
			}
		}
		if (str[i])
			i++;
	}
}
