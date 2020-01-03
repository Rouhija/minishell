/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 17:01:10 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/03 19:38:42 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**add_slot(size_t size)
{
	int		i;
	char	**new;

	i = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (size + 1))))
		exit_shell(2);
	while (g_env[i] && i < size - 1)
	{
		if (!(new[i] = ft_strdup(g_env[i])))
			exit_shell(2);
		free(g_env[i]);
		i++;
	}
	new[size] = NULL;
	free(g_env);
	return (new);
}

static void		set_env(char *key, char *value)
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
		g_env = add_slot(i + 1);
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

int				setenv_builtin(char **args)
{
	if (!args[0])
		display_env();
	else if (args[1] && args[2])
		ft_putendl("setenv: Too many arguments.");
	else
		set_env(args[0], args[1]);
	return (1);
}
