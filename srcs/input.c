/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 20:55:28 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 13:21:07 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*auto_complete(char **input, int *i, int *size)
{
	struct dirent	*dp;
	DIR				*dir;
	char			*pwd;
	int				len;
	char			*r;

	r = NULL;
	len = ft_strlen(*input);
	pwd = get_env("PWD");
	if (!(dir = opendir(pwd)))
		exit_shell(1);
	while ((dp = readdir(dir)))
	{
		if (ft_strstr((*dp).d_name, *input))
		{
			ft_putendl("MATCH");
			r = ft_strdup(&(*dp).d_name[len]);
			break ;
		}
		ft_putendl("pöö");
	}
	closedir(dir);
	return (r);
}

void			parse_dollars(char **input)
{

}

void			read_input(char **input)
{
	int		n_read;
	int		size;
	int		i;
	char	buf;
	// pid_t	pid;
	// int 	p[2];

	// if (pipe(p) < 0) 
	// 	exit_shell(1); 
	i = 0;
	size = 1;
	*input = ft_strnew(1);
	while ((n_read = read(0, &buf, 1) > 0) && buf != '\n')
	{
		// if (buf == '\t')
		// {
		// 	ft_putstr("\033[4J");
		// 	// tmp = auto_complete(input, &i, &size);
		// 	pid = fork();
		// 	// signal(SIGINT, child_signal_handler);
		// 	write(p[1], &tmp[0], 1);
		// 	// if (!pid)
		// 	// 	execv("/home/srouhe/hiver/minishell/minishell", args);
		// 	wait(NULL);
		// }
		// else
		// {
		*(*input + i++) = buf;
		*input = ft_realloc(*input, (size_t)size, (size_t)(size + 1));
		size++;
		// }
	}
	*(*input + i) = '\0';
	if (!n_read)
	{
		free(input);
		exit_shell(1);
	}
	ft_strchr(*input, '$') ? parse_dollars(input) : PASS;
	// parse $ and ~
}