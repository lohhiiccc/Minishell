#include "prompt.h"

static long long	get_id(char *str);

void	manage_history(char *str)
{
	static long long	id = -1;
	long long			tmp;

	if (id == -1)
	{
		add_history(str);
		return ;
	}
	tmp = get_id(str);
	if (tmp == id)
		return ;
	id = tmp;
	add_history(str);
}

static long long	get_id(char *str)//todo: voir si il y a mieux
{
	size_t	i;
	long long id;

	id = 1;
	i = 0;
	while (str[i])
	{
		if (i & 1)
			id *= str[i] % 5;
		else
			id += str[i] * 7;
		i++;
	}
	return (id);
}
