
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

void heredoc_back_slash(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\\' && s[i + 1] == '\0')
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			s[i] = 127;
		}
		else if (s[i] == '\\' && (s[i + 1] == '$' || s[i + 1] == '\\' || s[i] == '\n'))
		{
			ft_memmove(s + i, s + i + 1, ft_strlen(s + i + 1) + 1);
			s[i] = -s[i];
		}
		i++;
	}
}
