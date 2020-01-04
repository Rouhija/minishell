/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:37:39 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 20:55:41 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(int reason)
{
	ft_freestrarr(g_env);
	reason == 1 ? ft_putendl("other error.") : PASS;
	reason == 2 ? ft_putendl("malloc error.") : PASS;
	exit(reason);
}

int		main(int ac, char **av, char **env)
{
	int		r;
	char	*input;
	char	**cmds;

	init_env(ac, av, env);
	while (1)
	{
		display_prompt();
		signal(SIGINT, parent_signal_handler);
		read_input(&input);
		cmds = ft_strsplit(input, ' ');
		free(input);
		r = exec_cmd(cmds);
		ft_freestrarr(cmds);
		if (r < 0)
			break ;
	}
	ft_putstr("minishell: Thanks ");
	ft_putstr(get_env("USER"));
	ft_putendl(", bye! ⚡");
	ft_freestrarr(g_env);
	return (0);
}
