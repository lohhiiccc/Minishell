
#include <stdint.h>
#include "libft.h"

uint8_t is_charset(char c)
{
	return (ft_isalnum(c) || c == '_');
}
