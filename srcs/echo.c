/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:12:05 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 20:08:01 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		echo(char *arg)
{
	char	*parsed;
	char	quote[2];

	quote[0] = '"';
	quote[1] = '\0';
	parsed = ft_str_replace(ft_strdup(arg), quote, "");
	ft_putstr(parsed);
	free(parsed);
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
