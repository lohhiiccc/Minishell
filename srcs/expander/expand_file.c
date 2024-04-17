
#include <stdlib.h>
#include "expand_utils.h"
#include "expand.h"
#include "ft_printf.h"
#include "libft.h"

static uint8_t ambiguous_redirect(char *s);
int8_t	expand_file(char *s, t_env *env)
{
	size_t	i;
	char	*s2;

	s2 = ft_strdup(s);
	i = 0;
	if (0 != expand_str(&s, 0, env, s2))
		return (-1);
	if (NULL == s2)
		return (ambiguous_redirect(s2));
	while (s[i])
	{
		if (ft_isspace(s[i]))
			return (ambiguous_redirect(s2));
		i++;
	}
	free(s2);
	remove_quote(s);
	return (0);
}

static uint8_t ambiguous_redirect(char *s)
{
	ft_dprintf(2, "minichell: %s: ambiguous redirect\n", s);
	s = NULL;
	free(s);
	return (-1);
}
