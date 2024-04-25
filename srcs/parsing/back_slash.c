
#include <readline/readline.h>
#include "libft.h"

void prompt_back_slash(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\\')
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			s[i] = -s[i];
		}
		i++;
	}
}
