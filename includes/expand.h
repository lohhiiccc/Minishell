
#ifndef EXPAND_H
# define EXPAND_H

# include "env.h"

char	**expand_cmd(char **cmd, t_env *env);
int8_t	expand_file(char *s, t_env *env);
//int8_t	expand_file(char **s, t_env *env);
void	expand_delimiter(char *str);

#endif
