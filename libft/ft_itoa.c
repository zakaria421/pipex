/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:51:18 by zbentale          #+#    #+#             */
/*   Updated: 2022/10/31 17:53:43 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	result_len(int n)
{
	int	result_len;

	result_len = 0;
	if (n == 0)
		result_len++;
	while (n != 0)
	{
		n /= 10;
		result_len++;
	}
	return (result_len);
}

static char	*negative_number(int n, int result_x)
{
	char	*p;

	p = malloc(result_x + 2);
	if (!p)
		return (0);
	p[0] = '-';
	p[result_x + 1] = '\0';
	n = -n;
	while (n != 0)
	{
		p[result_x--] = '0' + (n % 10);
		n /= 10;
	}
	return (p);
}

static char	*positive_number(int n, int result_x)
{
	char	*p;

	p = malloc(result_x + 1);
	if (!p)
	{
		return (0);
	}
	p[result_x] = '\0';
	if (n == 0)
		p[0] = '0';
	while (n != 0)
	{
		p[--result_x] = '0' + (n % 10);
		n /= 10;
	}
	return (p);
}

static char	*int_min(int n, int result_x)
{
	char	*p;

	p = malloc(12);
	p[0] = '-';
	n += 1;
	p[11] = '\0';
	n = -n;
	while (n != 0)
	{
		p[result_x--] = '0' + (n % 10);
		n /= 10;
	}
	p[10] = '8';
	return (p);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		result_x;

	result_x = result_len(n);
	if (n == -2147483648)
	{
		p = int_min(n, result_x);
		return (p);
	}
	if (n < 0)
	{
		p = negative_number(n, result_x);
		return (p);
	}
	else
	{
		p = positive_number(n, result_x);
		return (p);
	}
}
