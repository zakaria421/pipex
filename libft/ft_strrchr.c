/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:55:13 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/29 21:48:05 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	a;
	int		i;

	a = (char) c;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == a)
			return (&((char *)str)[i]);
		i--;
	}
	return (0);
}
