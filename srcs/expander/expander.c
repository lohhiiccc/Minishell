
#include <stdlib.h>
#include "vector.h"
#include "expand.h"
#include "libft.h"
#include "ft_printf.h"

static void	set_negative(char *str);

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
		expand_quote(&cmd[i], quotes, &env->env);
		expand_ret(&cmd[i], env->ret, quotes);
		set_negative(cmd[i]);
		expand_var(&cmd[i], &env->env);
		str = ft_sprintf("%S%S ", str, cmd[i]);
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

static void	set_negative(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
			{
				str[i] = -str[i];
				i++;
			}
		}
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
			{
				str[i] = -str[i];
				i++;
			}
		}
		if (str[i])
			i++;
	}
}
