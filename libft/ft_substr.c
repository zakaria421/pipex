/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:15:38 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/29 21:35:37 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len == 0 || start > ft_strlen(s))
		return (p = malloc(1), p[i] = '\0', p);
	else if (len >= ft_strlen(s))
	{
		p = malloc((ft_strlen(s) - start) + 1);
		if (!p)
			return (NULL);
	}
	else
	{
		p = malloc(len + 1);
		if (!p)
			return (NULL);
	}
	while (i < len && s[start] != '\0')
		p[i++] = s[start++];
	return (p[i] = '\0', p);
}
