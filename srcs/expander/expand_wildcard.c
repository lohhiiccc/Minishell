
#include "expand_utils.h"
#include "libft.h"
#include "ft_printf.h"

char **expand_wildcard(char **cmd)
{
	size_t	i;
	char 	*str;

	i = 0;
	str = NULL;
	while (cmd[i])
	{
		if (have_wildcard(cmd[i]))
		{
			if (-1 == wildcard(cmd[i], &cmd[i]))
			{
				ft_free_tab(cmd + i);
				return (NULL);
			}
		}
		str = ft_sprintf("%S%s ", str, cmd[i]);
		if (NULL == str)
		{
			ft_free_tab(cmd + i);
			return (NULL);
		}
		i++;
	}
	return (ft_split(str, " \t\n"));
}

