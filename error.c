/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:42:49 by zbentale          #+#    #+#             */
/*   Updated: 2023/01/16 18:16:17 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(1);
}

void	ft_error(char *str, char *st)
{
	write(2, str, ft_strlen(str));
	write(2, st, ft_strlen(st));
	write(2, "\n", 1);
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
