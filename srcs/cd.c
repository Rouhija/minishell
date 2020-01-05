/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:55:11 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 16:17:47 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_to(char *path, int print)
{
	char	*tmp;
	char	*cwd;
	char	buffer[BUF_SIZE + 1];

	tmp = parse_path(path);
	cwd = getcwd(buffer, BUF_SIZE);
	if (!chdir(path))
	{
		set_env("OLDPWD", cwd);
		cwd = getcwd(buffer, BUF_SIZE);
		set_env("PWD", cwd);
		print ? ft_putendl(tmp) : PASS;
	}
	else
	{
		ft_putstr("cd: ");
		if (access(path, F_OK) == -1)
			ft_putstr("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied: ");
		else
			ft_putstr("not a directory: ");
		ft_putendl(path);			
	}
	free(tmp);
}

void	change_pwd(char **args)
{
	char	*cwd;

	cwd = ft_strdup(get_env("PWD"));
	if (args[2])
	{
		ft_putendl("cd: too many arguments");
	}
	else if (ft_strstr(cwd, args[0]))
	{
		cwd = ft_str_replace(cwd, args[0], args[1]);
		move_to(cwd, 1);
		free(cwd);
	}
	else
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putendl(args[0]);
	}
	
}

int		cd_builtin(char **args)
{
	if (!args[0])
		move_to(get_env("HOME"), 0);
	else if (args[0] && args[1])
		change_pwd(args);
	else if (ft_strequ(args[0], get_env("USER")) || ft_strequ(args[0], "--"))
		move_to(get_env("HOME"), 0);
	else if (ft_strequ(args[0], "-"))
		move_to(get_env("OLDPWD"), 1);
	else
		move_to(args[0], 0);
	return (1);
}
