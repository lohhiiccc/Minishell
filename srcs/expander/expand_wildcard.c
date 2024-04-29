
#include <stdlib.h>

#include "expand_utils.h"
#include "libft.h"
#include "ft_printf.h"

static void	*free_tab(char **tab, size_t start);
static char	**wildecard_fail(char **cmd, size_t i, char *str);

char	**expand_wildcard(char **cmd)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	while (cmd[i])
	{
		if (have_wildcard(cmd[i]))
		{
			if (wildcard(cmd[i], &cmd[i]) == -1)
				return (wildecard_fail(cmd, i, str));
		}
		str = ft_sprintf("%S%s ", str, cmd[i]);
		if (str == NULL)
		{
			return (free_tab(cmd, i));
		}
		free(cmd[i]);
		i++;
	}
	free(cmd);
	cmd = ft_split(str, " \t\n");
	free(str);
	return (cmd);
}

static char	**wildecard_fail(char **cmd, size_t i, char *str)
{
	free(str);
	return (free_tab(cmd, i));
}

static void	*free_tab(char **tab, size_t start)
{
	while (tab[start])
	{
		free(tab[start]);
		start++;
	}
	free(tab);
	return (NULL);
}
