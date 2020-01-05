/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 15:00:39 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 15:16:20 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Replaces all occurrances of `rep` with `wth` in string `org`.
*/

char		*ft_str_replace(char *org, char *rep, char *wth)
{
	char	*r;
	char	*tmp;
	char	*tmp2;
	char	*head;

	tmp = org;
	head = org;
	r = ft_strnew(ft_strlen(org) + (ft_strlen(wth) - ft_strlen(rep)));
	while ((tmp = ft_strstr(tmp, rep)))
	{
		r = ft_strncat(r, org, ft_strlen(org) - ft_strlen(tmp));
		r = ft_strcat(r, wth);
		tmp += ft_strlen(rep);
		org = tmp;
	}
	tmp2 = r;
	r = ft_strjoin(r, org);
	free(tmp2);
	free(head);
	return (r);
}
