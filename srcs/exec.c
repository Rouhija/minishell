/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:12:08 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 19:24:25 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char 	*args[] = {"/bin/ls", "srcs", "-l", NULL};
// execve("/bin/ls", args, NULL);

int		run_cmd(char *bin, char **cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_putendl("fork fail.");
		return (-1);
	}
	signal(SIGINT, sub_signal_handler);
	execve(bin, cmd, g_env);
	wait(&pid);
	return (1);
}

int		bins(char **cmd)
{
	int				i;
	char			**path;
	char			*exec;
	struct stat		attr;

	i = 0;
	path = ft_strsplit(get_env("PATH"), ':');
	while (path && path[i])
	{
		exec = ft_pathjoin(path[i], cmd[0]);
		if (!lstat(exec, &attr))
			return (run_cmd(exec, cmd));
		free(exec);
		i++;
	}
	ft_freestrarr(path);
	return (0);
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
	if ((r = builtins(cmd)) == 1)
		return (0);
	else if (r == -1)
		return (-1);
	else if (bins(cmd) == 1)
		return (0);
	ft_putstr("minishell: command not found: ");
	ft_putendl(cmd[0]);
	return (0);
}
