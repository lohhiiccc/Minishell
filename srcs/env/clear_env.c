
#include <stdlib.h>
#include "vector.h"
#include "env.h"

void	clear_env(t_vector *env)
{
	char **test;
	size_t i;

	i = 0;
	test = ft_vector_get(env, 0);
	while (i < env->nbr_elem)
	{
		free(test[i]);
		i++;
	}
	free(env->addr);
}
