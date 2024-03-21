
#include <stdio.h>
#include "vector.h"
#include "libft.h"

unsigned char	expand_parameter(t_vector *cmd, size_t *i, t_vector *env);
char *get_value(char *str, char **env);
void	fill_quote(unsigned char *quotes, char c);

char **expand_cmd(char **cmd, t_vector *env)
{
	t_vector	new_cmd;
	size_t	i;

	i = 0;
	if (-1 == ft_vector_init(&new_cmd, sizeof(char *)))
		return (NULL);
	while (cmd[i])
	{
		if (-1 == ft_vector_add_ptr(&new_cmd, cmd[i]))
			return (NULL);//todo free;
		if (expand_parameter(&new_cmd, &i, env))
			return (NULL);
		(void)env;
		i++;
	}
	if (-1 == ft_vector_add_ptr(&new_cmd, cmd[i]))
		return (NULL);//todo free;
	for (size_t j = 0; j < new_cmd.nbr_elem; ++j) {
		printf("%zu:%s\n", j, ((char **)new_cmd.addr)[j]);
	}
	return (ft_vector_get(&new_cmd, 0));
}

unsigned char	expand_parameter(t_vector *cmd, size_t *i, t_vector *env)
{
	char	*new;
	unsigned char	quotes[2];
	size_t	j;

	j = 0;
	ft_bzero(quotes, sizeof(unsigned char) * 2);
	while (((char **)cmd->addr)[*i][j])
	{
		fill_quote(quotes, ((char **)cmd->addr)[*i][j]);
		if (!quotes[0] && ((char **)cmd->addr)[*i][j] == '$')
		{
			((char **)cmd->addr)[*i][j] = '\0';
			new = get_value(((char **)cmd->addr)[*i] + j + 1, ft_vector_get(env, 0));
			if (new == NULL)
				return 1;//free ??
			if (-1 == ft_vector_add_ptr(cmd, new))
				return 1;
		}
		j++;
	}
	return (0);
}

char *get_value(char *str, char **env)
{
	char	*var;

	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	var	= ft_strdup(str);
	if (NULL == var)
		return (NULL);
	var[i] = '\0';
	j = 0;
	while (env && 0 != ft_strncmp(var, env[j], ft_strlen(var)))
		j++;
	return env[j] + i + 1;
}

void	fill_quote(unsigned char *quotes, char c)
{
	if (c == '\'' && quotes[1] != 1)
	{
		if (quotes[0] == 0)
			quotes[0] = 1;
		else
			quotes[0] = 0;
	}
	else if (c == '"' && quotes[0] != 1)
	{
		if (quotes[1] == 0)
			quotes[1] = 1;
		else
			quotes[1] = 0;
	}
}