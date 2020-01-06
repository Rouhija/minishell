/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 20:55:28 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/06 14:57:56 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			parse_dollars(char **input)
{
	int		i;
	char	*tmp;
	char	*var;
	char	*value;

	i = 1;
	tmp = *input;
	while ((tmp = ft_strchr(tmp, '$')))
	{
		while (tmp[i] != '\0' && tmp[i] != '$' && tmp[i] != '"'
				&& !ft_is_whitespace(tmp[i]))
			i++;
		var = ft_strsub(tmp, 0, i);
		if ((value = get_env(var + 1)))
		{
			*input = ft_str_replace(*input, var, value);
			tmp = *input;
		}
		tmp++;
		i = 1;
		free(var);
	}
}

static void			parse_tilde(char **input)
{
	char	*tmp;
	char	*value;

	tmp = *input;
	while ((tmp = ft_strchr(tmp, '~')))
	{
		if ((value = get_env("HOME")))
		{
			*input = ft_str_replace(*input, "~", value);
			tmp = *input;
		}
		tmp++;
	}
}

void				read_input(char **input)
{
	int		n_read;
	int		i;
	char	buf;

	i = 0;
	*input = ft_strnew(BUF_SIZE);
	while ((n_read = read(0, &buf, 1) > 0) && buf != '\n')
	{
		*(*input + i++) = buf;
	}
	*(*input + i) = '\0';
	if (!n_read)
	{
		if (input)
			free(*input);
		exit_shell(0);
	}
	ft_strchr(*input, '$') ? parse_dollars(input) : PASS;
	ft_strchr(*input, '~') ? parse_tilde(input) : PASS;
}
