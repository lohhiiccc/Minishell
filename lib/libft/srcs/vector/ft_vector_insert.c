
#include "libft.h"

int	ft_vector_insert(t_vector *vector, void *elem, size_t index, size_t n)
{
	while (vector->capacity < vector->nbr_elem + n)
		if (vector->capacity == vector->nbr_elem && ft_vector_resize(vector, vector->capacity * 2) == -1)
			return (-1);
	ft_memmove(vector->addr + ((index + n ) * vector->size), vector->addr + (index * vector->size), ((vector->nbr_elem - index) * vector->size));
	ft_memcpy(vector->addr + index, elem, vector->size);
	vector->nbr_elem++;
	return (0);
}
