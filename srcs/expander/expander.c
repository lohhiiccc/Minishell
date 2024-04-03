
#include <stdio.h>
#include <malloc.h>
#include "vector.h"
#include "libft.h"
#include "ft_printf.h"

//void	fill_quote(unsigned char *quotes, char c);

char **expand_cmd(char **cmd, t_vector *env)
{
	(void)env;
	return (cmd);
}

void	fill_quote(unsigned char *quotes, char c)
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
