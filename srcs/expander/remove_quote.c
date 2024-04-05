
#include "libft.h"
#include "ft_printf.h"

void	ft_swap(char *str, size_t a, size_t b);
void	remove_quote(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			continue;
		}
		else if (s[i] < 0)
			s[i] = -s[i];
		i++;
	}
	ft_printf("|%s|\n", s);
}