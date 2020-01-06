/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:01:10 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/06 17:44:57 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_env(char *key, char *value)
{
	int		i;
	char	*tmp;

	tmp = ft_strjoin(key, "=");
	i = find_env(key);
	if (g_env[i])
	{
		free(g_env[i]);
		if (value)
			g_env[i] = ft_strjoin(tmp, value);
		else
			g_env[i] = ft_strdup(tmp);
	}
	else
	{
		g_env = realloc_arr(i + 1);
		if (value)
			g_env[i] = ft_strjoin(tmp, value);
		else
			g_env[i] = ft_strdup(tmp);
	}
	free(tmp);
}

/*
**		Built in setenv command.
**		Arguments: KEY VALUE.
**		If no arguments, display current env variables.
*/

int		setenv_builtin(char **args)
{
	char	*tmp;

	if (!args[0])
		display_env();
	else if (args[1] && args[2])
		ft_putendl("setenv: too many arguments.");
	else if (args[1])
	{
		tmp = parse_quotes(args[1]);
		set_env(args[0], tmp);
		free(tmp);
	}
	else
		set_env(args[0], args[1]);
	return (1);
}
