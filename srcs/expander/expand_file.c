
#include <stdlib.h>
#include "expand_utils.h"
#include "expand.h"
#include "ft_printf.h"
#include "libft.h"

static int8_t	ambiguous_redirect(char *s);
static int8_t	convert_wildcard(char **str);
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
	if (-1 == convert_wildcard(&s))
		return (-1);
	free(s2);
	remove_quote(s);
	return (0);
}

static int8_t	convert_wildcard(char **str)
{
	char	**tab;

	tab = ft_null_alloc(2, sizeof(char *));
	if (NULL == tab)
		return (-1);
	tab[0] = *str;
	tab = expand_wildcard(tab);
	if (NULL == tab)
	{
		free(*str);
		return (-1);
	}
	if (tab[1])
	{
		ft_free_tab(tab);
		return (ambiguous_redirect(*str));
	}
	*str = tab[0];
	free(tab[1]);
	free((tab));
	return (0);
}

static int8_t ambiguous_redirect(char *s)
{
	ft_dprintf(2, "minichell: %e: ambiguous redirect\n", s);
	s = NULL;
	free(s);
	return (-1);
}
