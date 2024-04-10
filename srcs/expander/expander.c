
#include <stdlib.h>
#include "vector.h"
#include "expand.h"
#include "libft.h"
#include "ft_printf.h"


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

