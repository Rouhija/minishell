/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:37:39 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/03 19:00:13 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(int reason)
{
	ft_freestrarr(g_env);
	reason == 1 ? ft_putendl("other error.") : PASS;
	reason == 2 ? ft_putendl("malloc error.") : PASS;
	reason == 3 ? ft_putendl("keyboard interrupt.") : PASS;
	exit(reason);
}

void		read_input(char **input)
{
	int		n_read;
	int		size;
	int		i;
	char	buf;

	i = 0;
	size = 1;
	*input = ft_strnew(1);
	while ((n_read = read(0, &buf, 1) > 0) && buf != '\n')
	{
		*(*input + i++) = buf;
		*input = ft_realloc(*input, (size_t)size, (size_t)(size + 1));
		size++;
	}
	*(*input + i) = '\0';
	if (!n_read)
	{
		free(input);
		exit_shell(1);
	}
	// parse $ and ~
}

void	display_prompt(void)
{
	char buffer[1024 + 1];

	getcwd(buffer, 1024);
	ft_putstr(buffer);
	ft_putstr(" > ");
}

int		main(int ac, char **av, char **env)
{
	char	*input;
	char	**cmds;

	init_env(ac, av, env);
	while (1)
	{
		display_prompt();
		signal(SIGINT, signal_handler);
		read_input(&input);
		cmds = ft_strsplit(input, ' ');
		free(input);
		exec_cmd(cmds);
		ft_freestrarr(cmds);
	}
	return (0);
}
