/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:42:49 by zbentale          #+#    #+#             */
/*   Updated: 2023/01/19 22:10:44 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(126);
}

void	the_closer(int a, int b)
{
	close(a);
	close(b);
}

void	ft_error1(char *str, char *st)
{
	write(2, str, ft_strlen(str));
	if (st)
		write(2, st, ft_strlen(st));
	write(2, "\n", 1);
	exit(127);
}

void	ft_error2(char *str, char *st)
{
	write(2, str, ft_strlen(str));
	if (st)
		write(2, st, ft_strlen(st));
	write(2, "\n", 1);
}

void	ft_error3(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
