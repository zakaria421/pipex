/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:32:54 by zbentale          #+#    #+#             */
/*   Updated: 2023/01/17 18:13:33 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

typedef struct pipex
{
	char	**cmd;
	char	**paths;
	int		i;
	char	*save;
	int		fd[2];
	int		r;
	int		k;
	int		file1;
	int		file2;
}			t_pipex;
void		ft_perror(char *str);
void		the_closer(int a, int b);
void		ft_error1(char *str, char *st);
void		ft_error2(char *str, char *st);
void		ft_error3(char *str);

#endif
