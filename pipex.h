/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:32:54 by zbentale          #+#    #+#             */
/*   Updated: 2023/01/11 04:33:26 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./libft/libft.h"
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

#endif
