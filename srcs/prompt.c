/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:11:02 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 23:04:29 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*prompt_prefix(void)
{
	char	*user;
	char	*tmp;
	char	*r;

	user = get_env("USER");
	tmp = ft_strjoin(user, "@");
	r = ft_strjoin(tmp, "minishell");
	free(tmp);
	return (r);
}

char			*parse_path(char *cwd)
{
	char	*home;

	if (!cwd)
		return (NULL);
	home = get_env("HOME");
	if (!home)
		return (ft_strdup(cwd));
	else if (ft_strequ(cwd, home))
		return (ft_strdup("~"));
	else
		return (ft_pathjoin("~", cwd + ft_strlen(home)));
}

/*
**		Display prompt message.
**		Format: user@hostname:pwd>
*/

void			display_prompt(void)
{
	char	*prefix;
	char	*prompt;
	char	buffer[BUF_SIZE + 1];

	getcwd(buffer, BUF_SIZE);
	prefix = prompt_prefix();
	prompt = parse_path(buffer);
	ft_putstr(GREEN);
	ft_putstr(prefix);
	ft_putstr(NORMAL);
	ft_putchar(':');
	ft_putstr(BLUE);
	ft_putstr(prompt);
	ft_putstr(NORMAL);
	ft_strdel(&prefix);
	ft_strdel(&prompt);
	// ft_putstr("⚡ ");
	ft_putstr("> ");
}
