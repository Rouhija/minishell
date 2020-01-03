/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:11:21 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/03 15:44:54 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sub_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, sub_signal_handler);
	}
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar('\n');
		display_prompt();
		signal(SIGINT, signal_handler);
	}
}
