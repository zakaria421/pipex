/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:54:51 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/29 20:07:43 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	x;

	i = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	j = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	else if (dstsize < j)
		x = ft_strlen(src) + dstsize;
	else
		x = ft_strlen(src) + j;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && j < dstsize - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (x);
}
