/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 18:13:41 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/06 00:47:49 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		unset_env(int pos)
{
	char	*tmp;
	char	*del;

	tmp = g_env[pos];
	del = ft_strjoin(SH_UNSET, tmp);
	free(g_env[pos]);
	g_env[pos] = del;
}

/*
**		Built in unsetenv command.
**		One or multiple arguments.
**		Persist deleted env for later recovery.
*/

int				unsetenv_builtin(char **args)
{
	int		i;
	int		pos;

	i = 0;
	if (!args[0])
		ft_putendl("unsetenv: too few arguments.");
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
