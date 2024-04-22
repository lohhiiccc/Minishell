
#include <stdlib.h>
#include "expand_utils.h"
#include "libft.h"

static int		ft_sort(const char *s1, char *s2);
static void		ft_advanced_sort_string_tab(char **tab, int (*cmp)(const char *, char *));
static uint8_t	get_next(DIR *directory, struct dirent **dir_data);

char **get_folder(DIR *directory, struct dirent **dir_data, uint8_t include_hidden)
{
	t_vector	res;

	if (-1 == ft_vector_init(&res, sizeof(char *)))
		return (NULL);
	while (get_next(directory, dir_data))
	{
		if ((*dir_data)->d_name[0] == '.' && !include_hidden)
			continue;
		if (-1 == ft_vector_add_ptr(&res, ft_strdup((*dir_data)->d_name)))
		{
			ft_vector_free(&res, free);
			return (NULL);
		}
	}
	if (-1 == ft_vector_add_ptr(&res, NULL))
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

	if (NULL == tab)
		return ;
	i = 0;
	while (NULL != tab[i])
	{
		j = 0;
		while (NULL != tab[j])
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

static uint8_t get_next(DIR *directory, struct dirent **dir_data)
{
	*dir_data = readdir(directory);
	if (NULL != *dir_data)
		return (1);
	return (0);
}
