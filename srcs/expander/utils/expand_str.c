
#include "expand_utils.h"

int8_t	expand_str(char **str, size_t i, t_param *param, char *error)
{
	set_snegative(str[i]);
	if (expand_ret(&str[i], param->ret) == -1
		|| expand_var(&str[i], &param->env) == -1)
	{
		free_expand(str, i, error);
		return (-1);
	}
	set_negative(str[i]);
	return (0);
}
