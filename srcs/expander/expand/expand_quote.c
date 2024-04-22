
#include "libft.h"

void	remove_quote(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == 127)
			s[i] = '\0';
		if ((s[i] == '\'' || s[i] == '"') || (s[i] == '$'
			&& (s[i + 1] == '\'' || s[i + 1] == '"')))
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			continue;
		}
		if (s[i] < 0)
			s[i] = -s[i];
		i++;
	}
}