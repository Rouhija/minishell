/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 18:37:39 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/19 19:12:05 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av)
{
	char *path;
	char *args[] = {av[1], "-l", NULL};

	path = ft_pathjoin("/bin", av[1]);
	execv(path, &av[2]);
	perror("execv");
	return (0);
}
