/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:11:02 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 19:12:03 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*parse_host(void)
{
	char	*user;
	char	*host;
	char	*tmp;
	char	*r;

	user = get_env("USER");
	host = get_env("NAME");
	tmp = ft_strjoin(user, "@");
	r = ft_strjoin(tmp, host);
	free(tmp);
	return (r);
}

static char	*parse_path(char *cwd)
{
	char	*home;
	char	*propmt;

	if (!cwd)
		return (NULL);
	home = get_env("HOME");
	if (ft_strequ(cwd, home))
		return (ft_strdup("~"));
	else
		return (ft_pathjoin("~", cwd + ft_strlen(home)));
}

/*
**		Display prompt message.
**		Format: user@hostname:pwd>
*/

void		display_prompt(void)
{
	char	*host;
	char	*prompt;
	char 	buffer[BUF_SIZE + 1];

	getcwd(buffer, BUF_SIZE);
	host = parse_host();
	prompt = parse_path(buffer);
	ft_putstr(GREEN);
	ft_putstr(host);
	ft_putstr(NORMAL);
	ft_putchar(':');
	ft_putstr(BLUE);
	ft_putstr(prompt);
	ft_putstr(NORMAL);
	ft_strdel(&host);
	ft_strdel(&prompt);
	ft_putstr("☭> ");
}