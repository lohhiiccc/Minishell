#include "libft.h"

void	*ft_null_alloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_len;

	total_len = nmemb * size;
	if (total_len != 0 && total_len / size != nmemb)
		return (NULL);
	ptr = malloc(total_len);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr + total_len - size, size);
	return (ptr);
}
