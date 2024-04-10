
#include <stdint.h>
#include <stdlib.h>
#include "libft.h"
#include "vector.h"
#include "ft_printf.h"
#include "expand.h"

static int8_t new_str(t_vector *vector, char *str, uint8_t ret);
static int8_t vector_put_ret(char *num, uint8_t ret, t_vector *vector);

int8_t expand_ret(char **str, uint8_t ret)
{
	size_t	i;
	char *s;
	t_vector new;

	s = *str;

	i = 0;
	while (s[i])
	{
		if ((s[i + 1] && (s[i] == '$' && s[i + 1] == '?')))
		{
			if (-1 == ft_vector_init(&new, sizeof(char)))
				return (-1);
			if (-1 == new_str(&new, s, ret))
			{
				ft_vector_free(&new, NULL);
				return (-1);
			}
			free(*str);
			*str = ft_vector_get(&new, 0);
			return (0);
		}
		i++;
	}
	return (0);
}

static int8_t new_str(t_vector *vector, char *str, uint8_t ret)
{
	static char	num[] = "0123456789";
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && (str[i] == '$' && str[i + 1] == '?'))
		{
			vector_put_ret(num, ret, vector);
			i += 1;
		}
		else
			if (-1 == ft_vector_add(vector, &str[i]))
				return (-1);
		i++;
	}
	return (ft_vector_add(vector, &num[10]));
}

static int8_t vector_put_ret(char *num, uint8_t ret, t_vector *vector)
{
	if (ret < 10)
		return ft_vector_add(vector, &num[ret]);
	else if (ret < 100)
	{
		if (-1 == ft_vector_add(vector, &num[ret / 10]))
			return (-1);
		return ft_vector_add(vector, &num[ret % 10]);
	}
	else
	{
		if (-1 == ft_vector_add(vector, &num[(ret / 100)]))
			return (-1);
		if (-1 == ft_vector_add(vector, &num[(ret / 10) % 10]))
			return (-1);
		return ft_vector_add(vector, &num[ret % 10]);
	}
}