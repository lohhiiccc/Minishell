
#include "expand_utils.h"
#include "libft.h"

int8_t	expand_wildcard(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (have_wildcard(cmd[i]))
		{
			if (-1 == wildcard(cmd[i], &cmd[i]))
			{
				ft_free_tab(cmd + i);
				return (-1);
			}
		}
		remove_quote(cmd[i]);
		i++;
	}
	return (0);
}

