/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:37:39 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/23 16:02:06 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(int reason)
{
	reason == 3 ? ft_putendl("keyboard interrupt.") : PASS;
	exit(reason);
}

int		read_input(char **input)
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
	if (!n_read)
		exit_shell(1);
	*(*input + i) = '\0';
}

void	prompt(void)
{
	char buffer[1024 + 1];

	getcwd(buffer, 1024);
	ft_putstr(buffer);
	ft_putstr(" > ");
}

void	get_envv(int ac, char **av, char **env)
{
	int		i;
	int		size;

	size = 0;
	while (env[size])
		size++;
	i = 0;
	(void)ac;
	(void)av;
	if (!(g_env = (char **)malloc(sizeof(char*) * (size + 1))))
		exit_shell(2);
	while (env[i])
	{
		if (!(g_env[i] = ft_strdup(env[i])))
			exit_shell(2);
		i++;
	}
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\n");
		prompt();
		signal(SIGINT, signal_handler);
	}
}

int		main(int ac, char **av, char **env)
{
	char 	*path;
	char 	*args[] = {"/bin/ls", "-R", NULL};
	char	*input;

	// path = ft_pathjoin("/bin", av[1]);
	// execv("/bin/ls", args);
	get_envv(ac, av, env);
	prompt();
	while (1)
	{
		signal(SIGINT, signal_handler);
		read_input(&input);
		ft_putendl(input);
		while (*g_env)
		{
			ft_putendl(*g_env);
			*g_env++;
		}
		}
	// perror("execv");
	free(input);
	return (0);
}
