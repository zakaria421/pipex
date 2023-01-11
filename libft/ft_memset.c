/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:54:09 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/31 18:37:13 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t			i;
	unsigned char	*j;

	i = 0;
	j = b;
	while (i < len)
	{
		j[i] = (unsigned char)c;
		i++;
	}
	return (j);
}
