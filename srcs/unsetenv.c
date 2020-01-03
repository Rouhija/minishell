/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 18:13:41 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/03 19:21:51 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		delete_env(int i)
{
	ft_strdel(&g_env[i]);
	while (g_env[i + 1])
	{
		g_env[i] = ft_strdup(g_env[i + 1]);
		free(g_env[i + 1]);
		i++;
	}
	g_env = env_realloc(env_len(g_env) - 1);
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
