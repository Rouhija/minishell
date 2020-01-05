/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 14:56:31 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 18:36:23 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*get_env(char *var)
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
			return (ft_strchr(g_env[i], '=') + 1);
		}
		free(parsed);
		i++;
	}
	return (NULL);
}

char	**realloc_arr(size_t size)
{
	int		i;
	char	**new;

	i = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (size + 1))))
		exit_shell(2);
	while (g_env[i] && i < (int)(size - 1))
	{
		if (!(new[i] = ft_strdup(g_env[i])))
			exit_shell(2);
		ft_strdel(&g_env[i]);
		i++;
	}
	while (g_env[i])
	{
		ft_strdel(&g_env[i]);
		i++;
	}
	new[size] = NULL;
	free(g_env);
	g_env = NULL;
	return (new);
}
