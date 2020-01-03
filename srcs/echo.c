/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:12:05 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/03 18:20:57 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		echo(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (arg[0] == '"' && arg[len - 1] == '"')
		ft_putnstr(arg + 1, len - 2);
	else if (arg[0] == '"')
		ft_putstr(arg + 1);
	else if (arg[len - 1] == '"')
		ft_putnstr(arg, len - 1);
	else
		ft_putstr(arg);
}

/*
**		Builtin echo command.
**		Checks for no newline (-n) flag and parses quotes.
*/

int				echo_builtin(char **args)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (!args[i])
	{
		ft_putchar('\n');
		return (1);
	}
	if (ft_strequ(args[i], "-n"))
		flag = 1;
	i += flag;
	while (args[i])
	{
		echo(args[i]);
		i++;
		if (args[i])
			ft_putchar(' ');
	}
	if (!flag)
		ft_putchar('\n');
	return (1);
}
