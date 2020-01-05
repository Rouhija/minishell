/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:37:39 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 15:29:25 by srouhe           ###   ########.fr       */
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
		if (ft_str_isempty(input))
		{
			free(input);
			continue ;
		}
		cmds = ft_strsplit(input, ' ');
		free(input);
		r = exec_cmd(cmds);
		// ft_printf("return: %d\n", r);
		ft_freestrarr(cmds);
		if (r < 0)
			break ;
	}
	ft_putstr("minishell: ");
	ft_putstr(get_env("USER"));
	ft_putendl(" exit.");
	ft_freestrarr(g_env);
	return (0);
}
