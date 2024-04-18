
#include <unistd.h>
#include <stdlib.h>
#include "expand_utils.h"
#include "ft_printf.h"
#include "libft.h"

int8_t	wildcard(char **str, t_env *env)
{
	DIR				*directory;
	struct dirent	*dir_data;
	char 			**folder;

	(void)env;
	(void)str;
	dir_data = NULL;
	directory = opendir(".");
	if (NULL == directory)
		return (-1);
	folder = get_folder(directory, &dir_data);
	closedir(directory);
	if (NULL == folder)
		return (-1);

	for (int i = 0; folder[i]; i++) {
		ft_printf("%s ", folder[i]);
		free(folder[i]);
	}
	ft_printf("\n");
	free(folder);
	return (0);
}

