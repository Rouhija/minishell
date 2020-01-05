/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:37:39 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 15:43:37 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			exit_shell(int reason)
{
	ft_freestrarr(g_env);
	reason == 1 ? ft_putendl("other error.") : PASS;
	reason == 2 ? ft_putendl("malloc error.") : PASS;
	exit(reason);
}

static int		exec_commands(char **cmds)
{
	int		i;
	int		r;
	char 	**command;

	i = 0;
	r = 0;
	while (cmds[i])
	{
		command = ft_strsplit(cmds[i], ' ');
		r = exec_cmd(command);
		ft_freestrarr(command);
		i++;
		if (r == -1)
			break ;
	}
	return (r);
}

int				main(int ac, char **av, char **env)
{
	int		r;
	char	*input;
	char	**cmds;

	r = 0;
	init_env(ac, av, env);
	while (1)
	{
		display_prompt();
		signal(SIGINT, parent_signal_handler);
		read_input(&input);
		if (ft_str_isempty(input))
		{
			free(input);
			continue ;
		}
		cmds = ft_strsplit(input, ';');
		free(input);
		r = exec_commands(cmds);
		// ft_printf("return: %d\n", r);
		ft_freestrarr(cmds);
		if (r < 0)
			break ;
	}
	ft_putendl("minishell: graceful exit.");
	ft_freestrarr(g_env);
	return (0);
}
