/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:55:11 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 18:03:47 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	move_to(char *path, int print)
{
	char	*cwd;
	char	buffer[BUF_SIZE + 1];

	cwd = getcwd(buffer, BUF_SIZE);
	if (!chdir(path))
	{
		set_env("OLDPWD", cwd);
		print ? ft_putendl(path) : PASS;
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
}

int		cd_builtin(char **args)
{
	char	*home;

	if (!args[0]
		|| ft_strequ(args[0], "~")
		|| ft_strequ(args[0], get_env("USER"))
		|| ft_strequ(args[0], "--"))
		move_to(home, 0);
	else if (ft_strequ(args[0], "-"))
		move_to(get_env("OLDPWD"), 1);
	else
		move_to(args[0], 0);
	return (1);
}