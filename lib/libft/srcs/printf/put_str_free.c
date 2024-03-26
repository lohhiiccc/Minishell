#include "printf_utils.h"
#include "libft.h"
#include <stdlib.h>

int	put_strfree(t_vector *v, va_list arg)
{
	char	*str;
	char 	*args;

	args = (va_arg(arg, char *));
	str = ft_strdup(args);
	if (!str)
		return (-1);
	if (ft_vector_add_n(v, str, ft_strlen(str)) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	free(args);
	return (0);
}
