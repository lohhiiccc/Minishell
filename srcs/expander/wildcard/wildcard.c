
#include "expand_utils.h"
#include "libft.h"

void	fix_patern(char *patern);

int8_t	wildcard(char *patern, char **wildcard)
{
	DIR				*directory;
	struct dirent	*dir_data;
	char			**folder;
	uint8_t			is_folder;

	dir_data = NULL;
	directory = opendir(".");
	if (directory == NULL)
		return (-1);
	fix_patern(patern);
	is_folder = patern[ft_strlen(patern) - 1] == '/';
	folder = get_folder(directory, &dir_data, (patern[0] == '.'), is_folder);
	closedir(directory);
	if (NULL == folder)
		return (-1);
	return (fill_wildecard(patern, folder, wildcard, is_folder));
}

void	fix_patern(char *patern)
{
	size_t	len;

	len = ft_strlen(patern) - 1;
	while (patern[len] == '/' && patern[len - 1] == '/')
	{
		patern[len] = '\0';
		len--;
	}
}
