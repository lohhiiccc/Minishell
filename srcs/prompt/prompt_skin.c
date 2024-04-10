
#include <unistd.h>
#include "prompt.h"
#include "ft_printf.h"

char	*prompt_value(int last_ret)
{
	char	*prompt;
	char	*pwd;
	char	*line;

	pwd = getcwd(NULL, 0);
	if (last_ret != 0)
		prompt = ft_sprintf(PROMPTSKIN, RED, E_EGG2, END, pwd, UNDERLINE, RED, END, YELLOW, END);
	else
		prompt = ft_sprintf(PROMPTSKIN, GREEN, E_EGG, END, pwd, UNDERLINE, LIGHTGREEN, END, YELLOW, END);
	free(pwd);
	if (!prompt)
	{
		line = readline("[x] [error] Minishell$ ");
		return line;
	}
	line = readline(prompt);
	free(prompt);
	return (line);
}

