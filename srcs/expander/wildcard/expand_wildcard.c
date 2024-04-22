
#include <stdlib.h>
#include "vector.h"
#include "ft_printf.h"
#include "expand_utils.h"
#include "libft.h"

static int8_t	add_wildcard_in_vector(t_vector *res, char **folder, char *patern);
static int8_t	free_folder(char **folder, size_t i);

int8_t  expand_wild(char *patern, char **folder, char **str)
{
	t_vector	res;
	char		c;
	int8_t		ret;

	if (-1 == ft_vector_init(&res, sizeof(char)))
		return (-1);
	ret = add_wildcard_in_vector(&res, folder, patern);
	if (ret == -1)
	{
		ft_vector_free(&res, NULL);
		return (-1);
	}
	else if (ret == 10)
	{
		if (-1 == ft_vector_add_n(&res, patern, ft_strlen(patern)))
		{
			ft_vector_free(&res, NULL);
			return (-1);
		}
	}
	c = '\0';
	ret = ft_vector_add(&res, &c);
	*str = ft_vector_get(&res, 0);
	return (ret);
}

static int8_t add_wildcard_in_vector(t_vector *res, char **folder, char *patern)
{
	size_t	i;
	char	*buffer;
	int8_t	save;

	i = 0;
	buffer = NULL;
	while (folder[i])
	{
		if (is_match(folder[i], patern, 0, 0))
		{
			buffer = ft_sprintf("%S%s ", buffer, folder[i]);
			if (NULL == buffer)
				return (free_folder(folder, i));
		}
		free(folder[i]);
		i++;
	}
	free(folder);
	if (buffer == NULL)
		return (10);
	save = ft_vector_add_n(res, buffer, ft_strlen(buffer));
	free(buffer);
	return (save);
}

static int8_t	free_folder(char **folder, size_t i)
{
	while (folder[i])
	{
		free(folder);
		i++;
	}
	free(folder);
	return (-1);
}
