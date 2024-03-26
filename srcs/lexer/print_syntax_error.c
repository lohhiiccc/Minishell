
#include <unistd.h>
#include "vector.h"
#include "token.h"

char print_syntax_error(t_vector *tokens)
{
	free_token(tokens);
	write(2, "error\n", 6);
	return (-1);
}