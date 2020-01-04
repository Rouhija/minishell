/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:12:08 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 18:04:02 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char 	*args[] = {"/bin/ls", "srcs", "-l", NULL};
// execve("/bin/ls", args, NULL);

int		run_cmd(char **cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl("fork fail.");
		return (-1);
	}
	signal(SIGINT, sub_signal_handler);
	execve(cmd[0], cmd, g_env);
	wait(&pid);
	return (1);
}

int		builtins(char **cmd)
{
	if (ft_strequ(cmd[0], "exit"))
		return (-1);
	else if (ft_strequ(cmd[0], "echo"))
		return (echo_builtin(cmd + 1));
	else if (ft_strequ(cmd[0], "cd"))
		return (cd_builtin(cmd + 1));
	else if (ft_strequ(cmd[0], "setenv"))
		return (setenv_builtin(cmd + 1));
	else if (ft_strequ(cmd[0], "unsetenv"))
		return (unsetenv_builtin(cmd + 1));
	else if (ft_strequ(cmd[0], "env"))
		return (display_env());
	return (0);
}

int		exec_cmd(char **cmd)
{
	int r;
	// ft_printf("cmd[0]: %s\n", cmd[0]);
	if ((r = builtins(cmd)) == 1)
		return (0);
	else if (r == -1)
		return (-1);
	// else
	// 	run_cmd(cmd);
	ft_putstr("minishell: command not found: ");
	ft_putendl(cmd[0]);
	return (0);
}
