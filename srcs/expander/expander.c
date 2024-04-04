
#include "vector.h"
#include "expand.h"
#include "libft.h"

//void	fill_quote(unsigned char *quotes, char c);

char **expand_cmd(char **cmd, t_vector *env)
{
	(void)env;
	uint8_t quotes[2];
	ft_bzero(quotes, sizeof(uint8_t) * 2);
	expand_quote(&cmd[0], quotes, env);
	return (cmd);
}