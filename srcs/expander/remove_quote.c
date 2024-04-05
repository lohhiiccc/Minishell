
#include "libft.h"

void	remove_quote(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '"' || s[i] == '\'')
			ft_memmove(s + i, s+ i + 1, ft_strlen(s + i + 1));
		i++;
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			s[i] = '\0';
		if (s[i] < 0)
			s[i] = -s[i];
		i++;
	}
//	s[i - count] = '\0';
}