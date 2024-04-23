
#include <stdint.h>
#include <stddef.h>

static char	match_abs(char c);
uint8_t is_match(char *str, char *patern, size_t i, size_t j)
{
	while ((patern[j] && patern[j] == '*' && patern[j + 1] == '*')
			|| (patern[j] =='\'' || patern[j] == '"'))
		j++;
	if (match_abs(patern[j]) && match_abs(patern[j]) == '/' && !match_abs(patern[j + 1]))
		return (1);
	if (!str[i] && !match_abs(patern[j]))
		return (1);
	if (match_abs(patern[j]) == '*')
		return (is_match(str, patern, i , j + 1)
			|| (str[i] && is_match(str, patern, i + 1, j)));
	if ((match_abs(patern[j]) == '?' && str[i]) || match_abs(patern[j]) == str[i])
		return (is_match(str, patern, i + 1, j + 1));
	return (0);
}

static char	match_abs(char c)
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