
#include "libft.h"
#include "tree.h"
#include "ft_printf.h"
#include <readline/readline.h>
#include <stdlib.h>
#define HERE_DOC_EOF "Minichell: warning: here-document delimited by end-of-file (wanted `%s')\n"
extern int g_sig_value;

static int8_t error(char *str, t_vector *v);
int read_here_doc(t_tree *tree)
{
	t_vector	content;
	char		*buffer;

	if (-1 == ft_vector_init(&content, sizeof(char *)))
		return (-1);
	g_sig_value = 0;
	buffer = readline("le croquant > ");
	while (!g_sig_value && buffer && ft_strcmp(buffer, (char *)tree->structur))
	{
		if (-1 == ft_vector_add_ptr(&content, buffer))
			return (error(buffer, &content));
		buffer = readline("le croquant > ");
	}
	if (g_sig_value)
		free(buffer);
	else if (!buffer)
		ft_dprintf(2, HERE_DOC_EOF, ((char *)tree->structur));
	if (-1 == ft_vector_add_ptr(&content, NULL))
		return (error(buffer, &content));
	free(tree->structur);
	tree->structur = ft_vector_get(&content, 0);
	return (g_sig_value);
}

static int8_t error(char *str, t_vector *v)
{
	ft_vector_free(v, free);
	free(str);
	return (-1);
}
