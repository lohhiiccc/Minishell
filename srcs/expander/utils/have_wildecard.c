
#include <stddef.h>
#include <stdint.h>

uint8_t have_wildcard(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '*' || str[i] == '?')
			return (1);
		i++;
	}
	return (0);
}
