
#include "expand_utils.h"
#include "libft.h"

int8_t wildcard(char *patern, char **wildcard)//todo : wildcard not working with quotes
{
	DIR				*directory;
	struct dirent	*dir_data;
	char 			**folder;

	dir_data = NULL;
	directory = opendir(".");
	if (NULL == directory)
		return (-1);
	if (patern[0] == '.')
		folder = get_folder(directory, &dir_data, 1);
	else
		folder = get_folder(directory, &dir_data, 0);
	closedir(directory);
	if (NULL == folder)
		return (-1);
	return (expand_wild(patern, folder, wildcard));
}
