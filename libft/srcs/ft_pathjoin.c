/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:47:10 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/19 19:04:54 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Join directory and file into a path
*/

char			*ft_pathjoin(char *dirname, char *filename)
{
	char	*path;
	char	*tmp;

	if (dirname[ft_strlen(dirname) - 1] == '/')
		path = ft_strjoin(dirname, filename);
	else
	{
		tmp = ft_strjoin(dirname, "/");
		path = ft_strjoin(tmp, filename);
		free(tmp);
	}
	return (path);
}
