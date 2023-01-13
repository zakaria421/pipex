/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:42:49 by zbentale          #+#    #+#             */
/*   Updated: 2023/01/13 06:23:32 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str)
{
	perror("ERROR");
	exit(1);
}

void	ft_error(char *str,char *st)
{
	write(2, str, ft_strlen(str));
	write(2, st, ft_strlen(st));
	write(2, "\n", 1);
	exit(1);
}

void	ft_error1(char *str,char *st)
{
	write(2, str, ft_strlen(str));
	write(2, st, ft_strlen(st));
	write(2, "\n", 1);
    exit(1);
}
void	ft_error2(char *str,char *st)
{
	write(2, str, ft_strlen(str));
    write(2, st, ft_strlen(st));
	write(2, "\n", 1);
}
void	ft_error3(char *str)
{
	write(2, str, ft_strlen(str));
    exit(1);
}
