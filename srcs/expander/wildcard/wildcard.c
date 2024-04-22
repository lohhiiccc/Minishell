
#include "expand_utils.h"
#include "libft.h"
#include "ft_printf.h"

void	fix_patern(char *patern);
int8_t wildcard(char *patern, char **wildcard)//todo : wildcard not working with quotes
{
	DIR				*directory;
	struct dirent	*dir_data;
	char 			**folder;
	uint8_t			is_folder;

	dir_data = NULL;
	directory = opendir(".");
	if (NULL == directory)
		return (-1);
	fix_patern(patern);
	is_folder = patern[ft_strlen(patern) - 1] == '/';
	if (patern[0] == '.')
		folder = get_folder(directory, &dir_data, 1, is_folder);
	else
		folder = get_folder(directory, &dir_data, 0, is_folder);
	closedir(directory);
	if (NULL == folder)
		return (-1);
	return (expand_wild(patern, folder, wildcard, is_folder));
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