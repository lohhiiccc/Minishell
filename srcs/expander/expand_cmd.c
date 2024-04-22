#include "ft_printf.h"
#include <stdlib.h>
#include "expand_utils.h"
#include "libft.h"

char **expand_cmd(char **cmd, t_env *env)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	while (cmd[i])
	{
		if (0 != expand_str(cmd, i, env, str))
			return (NULL);
		str = ft_sprintf("%S%s ", str, cmd[i]);
		if (NULL == str)
			return (free_expand(cmd, i, str));
		free(cmd[i]);
		i++;
	}
	free(cmd);
	cmd = ft_split(str, " \t\n");
	free(str);
	if (NULL == cmd)
		return (NULL);
	if (-1 == expand_wildcard(cmd))
		return (NULL);
	return (cmd);
}

