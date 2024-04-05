
#include <stdint.h>

static void next_quote(uint8_t *next, uint8_t *quotes);
void	fill_quote(unsigned char *quotes, char c)
{
	static uint8_t next[2] = {0,0};

	next_quote(next, quotes);
	if (c == '\'' && quotes[1] != 1)
	{
		if (quotes[0] == 0)
			quotes[0] = 1;
		else
			next[0] = 1;
	}
	else if (c == '"' && quotes[0] != 1)
	{
		if (quotes[1] == 0)
			quotes[1] = 1;
		else
			next[1] = 1;
	}
}

static void next_quote(uint8_t *next, uint8_t *quotes)
{
	if (next[0])
	{
		quotes[0] = 0;
		next[0] = 0;
	}
	if (next[1])
	{
		quotes[1] = 0;
		next[1] = 0;
	}
}
