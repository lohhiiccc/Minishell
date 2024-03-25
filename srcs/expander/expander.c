
#include <stdio.h>
#include <malloc.h>
#include "vector.h"
#include "libft.h"

void	fill_quote(unsigned char *quotes, char c);

char **expand_cmd(char **cmd, t_vector *env)
{
	t_vector t_cmd;

	if (-1 == ft_vector_init(&t_cmd, sizeof(char *)))
		return (NULL);

	return (ft_vector_get(&t_cmd, 0));
}

int	expand(char *arg, t_vector *vector)
{
	size_t			i;
	unsigned char	quote[2];
	char			*str;

	i = 0;
	str = ft_strdup(arg);
	while (arg[i])
	{
		fill_quote(quote, arg[i]);
		if (0 == quote[0] && arg[i] == '$' && (ft_isalnum(arg[i + 1]) || arg[i + 1] == '-'))
		{
			str[i] = '\0';
			if (1 == quote[1])
				;
			else
				;
		}
		i++;
	}
	free(arg);
	return (0);
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