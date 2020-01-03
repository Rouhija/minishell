/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 18:13:41 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/03 19:41:28 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		delete_env(int pos)
{
	int		i;
	int		j;
	int		len;
	char	**new;

	i = 0;
	j = 0;
	len = env_len(g_env);
	if (!(new = (char **)malloc(sizeof(char *) * (len))))
		exit_shell(2);
	while (g_env[j])
	{
		if (j == pos)
		{
			ft_strdel(&g_env[j]);
			j++;
		}
		if (!(new[i] = ft_strdup(g_env[j])))
			exit_shell(2);
		ft_strdel(&g_env[j]);
		i++;
		j++;
	}
	new[len - 1] = NULL;
	free(g_env);
	g_env = new;
}

int				unsetenv_builtin(char **args)
{
	int		i;
	int		pos;

	i = 0;
	if (!args[0])
		ft_putendl("unsetenv: Too few arguments.");
	else
	{
		while (args[i])
		{
			pos = find_env(args[i]);
			if (g_env[pos])
				delete_env(pos);
			i++;
		}
	}
	return (1);
}
