
#include <readline/readline.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "prompt.h"

char	*here_doc_rl(char *del)
{
	char	*str;
	char	*buffer;

	buffer = ft_sprintf("le croquant: [%s]> ", del);
	if (NULL != buffer)
	{
		str = readline(buffer);
		free(buffer);
	}
	else
		str = readline("le croquant > ");
	prompt_back_slash(str);
	return (str);
}