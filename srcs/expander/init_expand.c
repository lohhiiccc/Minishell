#include "env.h"

void    fill_quote(uint8_t quotes[2], char c)
{
	if (c == '\'' && quotes[1] != 1)
	{
		if (quotes[0] == 0)
			quotes[0] = 1;
		else
			quotes[0] = 0;
	}
	else if (c == '"' && quotes[0] != 1)
	{
		if (quotes[1] == 0)
			quotes[1] = 1;
		else
			quotes[1] = 0;
	}
}
