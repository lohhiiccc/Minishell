
#include <stdlib.h>

#include "vector.h"
#include "ft_printf.h"
#include "expand_utils.h"
#include "libft.h"

static int8_t	add_wildcard_in_vector(t_vector *res, char **folder, char *patern, uint8_t is_folder);
static int8_t	free_folder(char **folder, size_t i);
static char		*get_patern(uint8_t is_folder);
static int8_t	free_and_ret(t_vector *v);

int8_t  fill_wildecard(char *patern, char **folder, char **str, uint8_t is_folder)
{
	t_vector	res;
	char		c;
	int8_t		ret;

	if (ft_vector_init(&res, sizeof(char)) == -1)
	{
		ft_free_tab(folder);
		return (-1);
	}
	ret = add_wildcard_in_vector(&res, folder, patern, is_folder);
	if (ret == -1)
		return (free_and_ret(&res));
	else if (ret == 3 && ft_vector_add_n(&res, patern, ft_strlen(patern)) == -1)
		return (free_and_ret(&res));
	c = '\0';
	ret = ft_vector_add(&res, &c);
	free(*str);
	*str = ft_vector_get(&res, 0);
	return (ret);
}

static int8_t add_wildcard_in_vector(t_vector *res, char **folder, char *patern, uint8_t is_folder)
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
			buffer = ft_sprintf(get_patern(is_folder), buffer, folder[i]);
			if (buffer == NULL)
				return (free_folder(folder, i));
		}
		free(folder[i]);
		i++;
	}
	free(folder);
	if (buffer == NULL)
		return (3);
	save = ft_vector_add_n(res, buffer, ft_strlen(buffer));
	free(buffer);
	return (save);
}

static char *get_patern(uint8_t is_folder)
{
	if (is_folder)
		return (IS_FOLDER);
	return (IS_NOT_FOLDER);
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

static int8_t	free_and_ret(t_vector *v)
{
	ft_vector_free(v, NULL);
	return (-1);
}