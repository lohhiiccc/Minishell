
#include <stdlib.h>

void *free_expand(char **str, size_t i, char *error)
{
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	free(error);
	return (NULL);
}
