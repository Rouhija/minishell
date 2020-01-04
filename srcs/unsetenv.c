/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 18:13:41 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 17:06:20 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		unset_env(int pos)
{
	int	i;

	ft_strdel(&g_env[pos]);
	i = pos;
	while(g_env[i + 1])
	{
		g_env[i] = ft_strdup(g_env[i + 1]);
		ft_strdel(&g_env[i + 1]);
		i++;
	}
	g_env = realloc_arr(pos + i);
}

/*
**		Built in unsetenv command.
**		One or multiple arguments.
*/

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
				unset_env(pos);
			i++;
		}
	}
	return (1);
}
