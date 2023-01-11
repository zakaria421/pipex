/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:54:36 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/31 00:03:21 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	a;
	int		i;

	a = (char) c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			return (&((char *)str)[i]);
		i++;
	}
	if (a == '\0')
	{
		return (&((char *)str)[i]);
	}
	return (0);
}
