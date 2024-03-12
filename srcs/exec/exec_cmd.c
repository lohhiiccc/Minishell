/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuffard <mjuffard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 01:37:51 by mjuffard          #+#    #+#             */
/*   Updated: 2024/03/12 01:18:10 by mjuffard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "env.h"
#include <sys/wait.h>

static char	**create_env_tab(t_vector *env)
{
	char	**ret;
	t_env	*temp_env;
	char	*temp_str;
	size_t	i;

	i = 0;
	ret = malloc(sizeof(char *) * (env->nbr_elem + 1));
	temp_env = ft_vector_get(env, i);
	while (temp_env)
	{
		temp_str = ft_strjoin(temp_env->var_name, "=");
		ret[i] = ft_strjoin(temp_str, temp_env->var);
		free(temp_str);
		i++;
		temp_env = ft_vector_get(env, i);
	}
	ret[i] = NULL;
	return (ret);
}

static int	exec_child_cmd(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int	pid;
	int	ret;
	char	**env_tab;

	env_tab = create_env_tab(((t_cmd *)tree->structur)->env);
	pid = fork();
	if (pid == 0)
	{
		if (fd_in->nbr_elem > 0)
			if (dup2(*(int *)(fd_in->addr + ((fd_in->nbr_elem - 1) \
				* fd_in->size)), STDIN_FILENO))
				clean_exit(tree, fd_in, fd_out, 1);
		if (fd_out->nbr_elem > 0)
			if (dup2(*(int *)(fd_out->addr + ((fd_out->nbr_elem - 1) \
				* fd_out->size)), STDOUT_FILENO) == -1)
				clean_exit(tree, fd_in, fd_out, 1);
		close_vector_fd(fd_in);
		close_vector_fd(fd_out);
		execve(((t_cmd *)tree->structur)->path, \
			((t_cmd *)tree->structur)->arg, env_tab);
	}
	waitpid(pid, &ret, 0);
	return (ret);
}

int	exec_cmd(t_tree *tree, t_vector *fd_in, t_vector *fd_out)
{
	int		ret;

	if (is_build_in(((t_cmd *)tree->structur)->arg[0]))
		ret = exec_build_in(((t_cmd *)tree->structur)->arg);
	else
	{
		((t_cmd *)tree->structur)->path = find_path(((t_cmd *)\
			tree->structur)->arg[0], ((t_cmd *)tree->structur)->env);
		ret = exec_child_cmd(tree, fd_in, fd_out);
	}
	return (ret);
}
