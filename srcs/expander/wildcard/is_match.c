
#include <stdint.h>
#include <stddef.h>

static char	abs(char c);
uint8_t is_match(char *str, char *patern, size_t i, size_t j)
{
	while ((patern[j] && patern[j] == '*' && patern[j + 1] == '*')
			|| (patern[j] =='\'' || patern[j] == '"'))
		j++;
	if (abs(patern[j]) && abs(patern[j]) == '/' && !abs(patern[j + 1]))
		return (1);
	if (!str[i] && !abs(patern[j]))
		return (1);
	if (abs(patern[j]) == '*')
		return (is_match(str, patern, i , j + 1)
			|| (str[i] && is_match(str, patern, i + 1, j)));
	if ((abs(patern[j]) == '?' && str[i]) || abs(patern[j]) == str[i])
		return (is_match(str, patern, i + 1, j + 1));
	return (0);
}

static char	abs(char c)
{
	if (c < 0)
	{
		c = -c;
		if (c == '*' || c == '?' || c == '\'' || c == '"')
			c = -c;
		return (c);
	}
	return (c);
}