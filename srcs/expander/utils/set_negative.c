
#include "expand.h"

void	set_snegative(char *str)
{
	size_t		i;
	const char	c = '\'';

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

void	set_negative(char *str, char c)
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
