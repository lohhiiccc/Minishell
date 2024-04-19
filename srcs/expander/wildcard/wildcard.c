
#include <stdlib.h>
#include "expand_utils.h"
#include "ft_printf.h"
#include "libft.h"
int8_t  expand_wild(char *patern, char **folder, char **str);
int8_t	free_folder(char **folder, size_t i, t_vector *res);
int8_t add_wildcard_in_vector(t_vector *res, char **folder, char *patern, int8_t *have_match);

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

	//	for (int i = 0; folder[i]; i++) {
//		if (is_match(folder[i], patern, 0, 0))
//			ft_printf("%s", folder[i]);
//		free(folder[i]);
//	}
}

int8_t  expand_wild(char *patern, char **folder, char **str)
{
	t_vector	res;
	int8_t		have_match;

	have_match = 0;
	if (-1 == ft_vector_init(&res, sizeof(char)))
		return (-1);
	if (-1 == add_wildcard_in_vector(&res, folder, patern, &have_match))
		return (-1);
	if (!have_match)
	{
		have_match = ft_vector_add_n(&res, patern, ft_strlen(patern) + 1);
		*str = ft_vector_get(&res, 0);
		return (have_match);
	}
	*str = ft_vector_get(&res, 0);
	return (0);
}

int8_t add_wildcard_in_vector(t_vector *res, char **folder, char *patern, int8_t *have_match)
{
	size_t i;
	size_t len;
	char c = '\0';

	i = 0;
	while (folder[i])
	{
		if (is_match(folder[i], patern, 0, 0))
		{
			*have_match = 1;
			len = ft_strlen(folder[i]);
			folder[i][len] = ' ';
			if (-1 == ft_vector_add_n(res, folder[i], len + 1))
				return (free_folder(folder, i, res));
		}
		free(folder[i]);
		i++;
	}
	free(folder);
	return (-1 == ft_vector_add(res, &c));
}

int8_t	free_folder(char **folder, size_t i, t_vector *res)
{
	ft_vector_free(res, NULL);
	while (folder[i])
	{
		free(folder);
		i++;
	}
	free(folder);
	return (-1);
}