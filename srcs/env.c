/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:56:31 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/03 19:37:53 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

int		display_env(void)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		ft_putendl(g_env[i]);
		i++;
	}
	return (1);
}

int		find_env(char *var)
{
	int		i;
	char	*parsed;

	i = 0;
	while (g_env[i])
	{
		parsed = ft_strsub(g_env[i], 0, ft_lfind(g_env[i], '='));
		if (ft_strequ(parsed, var))
		{
			free(parsed);
			return (i);
		}
		free(parsed);
		i++;
	}
	return (i);
}

void	init_env(int ac, char **av, char **env)
{
	int		i;
	int		size;

	size = 0;
	while (env[size])
		size++;
	i = 0;
	(void)ac;
	(void)av;
	if (!(g_env = (char **)malloc(sizeof(char *) * (size + 1))))
		exit_shell(2);
	while (env[i])
	{
		if (!(g_env[i] = ft_strdup(env[i])))
			exit_shell(2);
		i++;
	}
	g_env[size] = NULL;
}
