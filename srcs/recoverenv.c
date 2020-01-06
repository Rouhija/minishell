/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recoverenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 00:30:11 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/06 14:51:13 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		recover_env(int pos)
{
	char	*tmp;

	tmp = ft_strdup(g_env[pos] + ft_strlen(SH_UNSET));
	free(g_env[pos]);
	g_env[pos] = tmp;
}

/*
**		Bonus built in recover command.
**		Recovers environment variables unset previously in this session.
*/

int				recover_builtin(char **args)
{
	int		i;
	int		pos;
	char	*tmp;

	i = 0;
	if (!args[0])
		ft_putendl("recover: too few arguments.");
	else
	{
		while (args[i])
		{
			tmp = ft_strjoin(SH_UNSET, args[i]);
			pos = find_env(tmp);
			if (g_env[pos])
				recover_env(pos);
			free(tmp);
			i++;
		}
	}
	return (1);
}
