/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:37:51 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/31 18:24:05 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_d;
	char	*src_c;

	dst_d = (char *)dst;
	src_c = (char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		while (len--)
		{
			dst_d[len] = src_c[len];
		}
	}
	return (dst);
}
