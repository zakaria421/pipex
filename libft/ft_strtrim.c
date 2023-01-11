/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:55:17 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/29 21:43:30 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find(char s1, char const *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (s1 == set[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		start;
	int		end;
	int		i;
	int		size;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	i = 0;
	size = 0;
	while (find(s1[start], set) == 1)
		start++;
	while (end > 0 && find(s1[end], set) == 1)
		end--;
	if (end > start)
		size = end - start + 1;
	p = malloc (size + 1);
	if (!p)
		return (NULL);
	while (start <= end)
		p[i++] = s1[start++];
	p[i] = '\0';
	return (p);
}
