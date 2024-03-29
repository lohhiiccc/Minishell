#include "prompt.h"

static long long	get_id(char *str);

void	manage_history(char *str)
{
	static unsigned long	id = 0;
	unsigned long			tmp;

	tmp = get_id(str);
	if (tmp == id)
		return ;
	id = tmp;
	add_history(str);
}

static long long	get_id(char *str)
{
	size_t			i;
	char			j;
	unsigned long	id;

	id = 5381;
	i = 0;
	while (str[i])
	{
		j = str[i];
		id = ((id << 5) + id) + j;
		i++;
	}
	return (id);
}
