
#include <unistd.h>
#include "prompt.h"
#include "ft_printf.h"

char	*prompt_value(int last_ret)
{
	char	*str;
	char	*ret;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (last_ret != 0)
		str = ft_sprintf(PROMPTSKIN, RED, E_EGG, END, pwd, UNDERLINE, RED, END, YELLOW, END);
	else
		str = ft_sprintf(PROMPTSKIN, GREEN, E_EGG2, END, pwd, UNDERLINE, LIGHTGREEN, END, YELLOW, END);
	free(pwd);
	if (!str)
	{
		ret = readline("[x] [error] Minishell$ ");
		return ret;
	}
	ret = readline(str);
	free(str);
	return (ret);
}

