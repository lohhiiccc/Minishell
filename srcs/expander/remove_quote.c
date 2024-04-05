
#include "libft.h"
#include "ft_printf.h"

void	ft_swap(char *str, size_t a, size_t b);
void	remove_quote(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
//		if (s[i] == '\'' || s[i] == '"')
//		{
//
//		}
		if (s[i] < 0)
			s[i] = -s[i];
		i++;
	}

}