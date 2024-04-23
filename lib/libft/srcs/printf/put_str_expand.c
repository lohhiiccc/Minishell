#include "printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	put_str_expand(t_vector *v, va_list arg)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_strdup(va_arg(arg, char *));
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] < 0)
			str[i] = -str[i];
		i++;
	}
		if (ft_vector_add_n(v, str, i) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (0);
}
