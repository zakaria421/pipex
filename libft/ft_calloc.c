/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:53:19 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/30 23:47:41 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	i = count * size;
	if (size && count > SIZE_MAX / size)
	{
		return (NULL);
	}
	p = malloc(i);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, i);
	return (p);
}
