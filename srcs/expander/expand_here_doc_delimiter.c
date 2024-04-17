
#include "expand_utils.h"

void expand_delimiter(char *str)
{
	set_snegative(str);
	set_negative(str);
	remove_quote(str);
}