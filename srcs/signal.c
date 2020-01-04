/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:11:21 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 20:53:57 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, child_signal_handler);
	}
}

void	parent_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		display_prompt();
		signal(SIGINT, parent_signal_handler);
	}
}
