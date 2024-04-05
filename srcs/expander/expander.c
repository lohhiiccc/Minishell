
#include "vector.h"
#include "expand.h"
#include "libft.h"
#include "ft_printf.h"

//void	fill_quote(unsigned char *quotes, char c);

char **expand_cmd(char **cmd, t_vector *env)
{
	uint8_t quotes[2];
	size_t	i;

	i = 0;
	ft_bzero(quotes, sizeof(uint8_t) * 2);
	while (cmd[i])
	{
		expand_quote(&cmd[i], quotes, env);
		remove_quote(cmd[i]);
		i++;
	}
	return (cmd);
}