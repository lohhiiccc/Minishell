
#ifndef EXPAND_H
# define EXPAND_H

#include <stdint.h>
#include "stddef.h"
#include "env.h"

char	**expand_cmd(char **cmd, t_env *env);
void	remove_quote(char *s);
size_t	get_envline(char **env, char *var);
uint8_t	is_charset(char c);
int8_t	expand_ret(char **str, uint8_t ret);
int8_t	expand_var(char **str, t_vector *env);
void	set_negative(char *str, char c);
void	set_snegative(char *str);
int8_t	add_var(char *s, size_t *i, t_vector *env, t_vector *vector);
int8_t	expand_str(char **str, size_t i, t_env *env, char *error);

#endif
