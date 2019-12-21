/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:37:39 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/21 15:16:41 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		display_prompt_msg();
		signal(SIGINT, signal_handler);
	}
}

void	prompt(void)
{
	char buffer[1024 + 1];

	getcwd(buffer, 1024);
	ft_putendl(buffer);
}

int		main(int ac, char **av, char **envv)
{
	char *path;
	char *args[] = {av[1], "-l", NULL};

	path = ft_pathjoin("/bin", av[1]);
	execv(path, &av[2]);
	prompt();
	while (1)
	{
		signal(SIGINT, signal_handler);
		// read input with read()
	}
	// perror("execv");
	return (0);
}
