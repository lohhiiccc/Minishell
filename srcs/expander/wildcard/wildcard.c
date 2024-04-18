
#include "prompt.h"
#include <unistd.h>
#include <stdlib.h>
#include "expand_utils.h"
#include "ft_printf.h"
#include "libft.h"

static uint8_t is_match(char *patern, char *str, size_t i, size_t j);
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
		is_match(patern, folder[i], 0 , 0);
		ft_printf("%s%s ", folder[i], END);
		free(folder[i]);
	}
	ft_printf("\n");
	free(folder);
	return (0);
}

static uint8_t is_match(char *patern, char *str, size_t i, size_t j)
{
	if (!patern[j] && !str[i])
		return (ft_printf("%s", GREEN), 0);
	while (patern[j])
	{
		if (patern[j] == str[i])
		{
			i++;
			j++;
			return (is_match(patern, str, i ,j));
		}
		else if (patern[j] == '*')
		{
			return (is_match(patern, str, i ,j + 1));
		}
		else if (patern[j] == '?')
		{
			j++;
			i++;
			return (is_match(patern, str, i ,j));
		}
		else
			return (ft_printf("%s", YELLOW), 1);
	}
	return (ft_printf("%s", RED), 1);
}