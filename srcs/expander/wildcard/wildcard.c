
#include <stdlib.h>
#include "expand_utils.h"
#include "ft_printf.h"
#include "libft.h"
int8_t  expand_wild(char *patern, char **folder, char **str);
int8_t	free_folder(char **folder, size_t i);
int8_t	add_wildcard_in_vector(t_vector *res, char **folder, char *patern);

int8_t wildcard(char *patern, char **wildcard)
{
	DIR				*directory;
	struct dirent	*dir_data;
	char 			**folder;

	dir_data = NULL;
	directory = opendir(".");
	if (NULL == directory)
		return (-1);
	folder = get_folder(directory, &dir_data);
	closedir(directory);
	if (NULL == folder)
		return (-1);

	return expand_wild(patern, folder, wildcard);
}

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

int8_t add_wildcard_in_vector(t_vector *res, char **folder, char *patern)
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

int8_t	free_folder(char **folder, size_t i)
{
	while (folder[i])
	{
		free(folder);
		i++;
	}
	free(folder);
	return (-1);
}