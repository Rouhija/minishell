/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 15:00:33 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/23 15:06:43 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_s, size_t new_s)
{
	void	*new;

	if (!ptr)
		return (NULL);
	if (!(new = ft_memalloc(new_s)))
	{
		free(ptr);
		return (NULL);
	}
	if (new_s > old_s)
		ft_memcpy(new, ptr, new_s);
	else
		ft_memcpy(new, ptr, old_s);
	free(ptr);
	return (new);
}