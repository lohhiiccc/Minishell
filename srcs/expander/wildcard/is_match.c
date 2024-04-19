
#include <stdint.h>
#include <stddef.h>

uint8_t is_match(char *str, char *patern, size_t i, size_t j)
{

	if (!str[i] && !patern[j])
		return (1);
	if (patern[j] == '*')
	{
		if (is_match(str, patern, i, j + 1))
			return (1);
		if (str[i])
			return (is_match(str, patern, i + 1, j));
	}
	if ((patern[j] == '?' && str[i]) || patern[j] == str[i])
		return (is_match(str, patern, i + 1, j + 1));
	return (0);
}
