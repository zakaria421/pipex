/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:53:54 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/30 23:55:53 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char *) s1;
	b = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (n > i)
	{
		if (a[i] != b[i])
		{
			return ((a[i]) - (b[i]));
		}
		i++;
	}
	return (0);
}
