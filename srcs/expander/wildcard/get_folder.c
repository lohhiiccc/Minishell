
#include <stdlib.h>
#include "expand_utils.h"
#include "libft.h"

static int		ft_sort(const char *s1, char *s2);
static void		ft_advanced_sort_string_tab(char **tab, int (*cmp)(const char *, char *));
static uint8_t	get_next(DIR *directory, struct dirent **dir_data, uint8_t dir);
static char		*get_str(char *str);

char **get_folder(DIR *directory, struct dirent **dir_data, uint8_t include_hidden, uint8_t dir)
{
	t_vector	res;

	if (ft_vector_init(&res, sizeof(char *)) == -1)
		return (NULL);
	while (get_next(directory, dir_data, dir))
	{
		if ((*dir_data)->d_name[0] == '.' && !include_hidden)
			continue;
		if (ft_vector_add_ptr(&res, get_str((*dir_data)->d_name)) == -1)
		{
			ft_vector_free(&res, free);
			return (NULL);
		}
	}
	if (ft_vector_add_ptr(&res, NULL) == -1)
	{
		ft_vector_free(&res, free);
		return (NULL);
	}
	ft_advanced_sort_string_tab(ft_vector_get(&res, 0), &ft_sort);
	return (ft_vector_get(&res, 0));
}

static void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(const char *, char *))
{
	size_t	i;
	size_t	j;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[j] != NULL)
		{
			if (cmp(tab[j], tab[i]) > 0)
				ft_swap(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
}

static int	ft_sort(const char *s1, char *s2)
{
	size_t	i;
	char	c1;
	char	c2;

	c1 = 0;
	c2 = 0;
	i = 0;
	while (s1[i])
	{
		c1 = ft_tolower(s1[i]);
		c2 = ft_tolower(s2[i]);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (c1 - c2);
}

static uint8_t get_next(DIR *directory, struct dirent **dir_data, uint8_t dir)
{
	*dir_data = readdir(directory);
	if (*dir_data == NULL)
		return (0);
	if ((*dir_data)->d_type != DT_DIR && dir)
		return (get_next(directory, dir_data, dir));
	return (1);
}

static char *get_str(char *str)
{
	size_t i;
	char *res;

	i = 0;
	res = ft_null_alloc(ft_strlen(str) + 1, sizeof(char));
	if (NULL == res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		if (res[i] == ' ' || res[i] == '\t'
			|| res[i] == '\n' || res[i] == '\''
			|| res[i] == '"' || res[i] == '*'
			|| res[i] == '?')
			res[i] = -res[i];
		i++;
	}
	return (res);
}
