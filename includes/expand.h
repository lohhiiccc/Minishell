
#ifndef EXPAND_H
# define EXPAND_H

#include <stdint.h>
#include "stddef.h"
#include "env.h"

char **expand_cmd(char **cmd, t_vector *env);
int8_t expand_quote(char **str, uint8_t *quote, t_vector *env);
void    fill_quote(uint8_t quotes[2], char c);
uint8_t is_charset(char c);

#endif
