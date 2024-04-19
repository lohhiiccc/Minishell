
#include "prompt.h"
#include <unistd.h>
#include <stdlib.h>
#include "expand_utils.h"
#include "ft_printf.h"
#include "libft.h"

static uint8_t is_match(char *patern, char *str, size_t i, size_t j);
//static	int8_t is_match(char *str, char *patern);
int8_t wildcard(char *patern)
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

	for (int i = 0; folder[i]; i++) {
		if (is_match(folder[i], patern, 0, 0))
			ft_printf("%s", folder[i]);
		free(folder[i]);
	}
	ft_printf("\n");
	free(folder);
	return (0);
}

static uint8_t is_match(char *str, char *patern, size_t i, size_t j)
{
	if (!str[i] && !patern[j])
		return (1);
	if (patern[j] == '*')
	{
		if (is_match(str, patern, i, j + 1))
			return (1);
		if (str[i])
			return (is_match(str, patern, i + 1, j));
	}
	if ((patern[j] == '?' && str[i]) || patern[j] == str[i])
		return (is_match(str, patern, i + 1, j + 1));
	return (0);
}
