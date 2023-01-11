/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:31:53 by zbentale          #+#    #+#             */
/*   Updated: 2023/01/11 05:05:46 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	the_closer(int a, int b)
{
	close(a);
	close(b);
}

void	pathfinder(t_pipex *pipex, char **envp)
{
	pipex->i = 0;
	while (envp[pipex->i])
	{
		if (ft_strncmp(envp[pipex->i], "PATH=", 5) == 0)
			pipex->save = envp[pipex->i] + 5;
		pipex->i++;
	}
	pipex->paths = ft_split(pipex->save, ':');
	pipex->i = 0;
}

void	ft_perror(char *str)
{
	perror("ERROR");
	exit(1);
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
void	ft_error1(char *str)
{
	write(2, str, ft_strlen(str));
}

void	firstchild(t_pipex pipex, char **envp, char **argv)
{
	dup2(pipex.fd[1], 1);
	dup2(pipex.file1, 0);
	the_closer(pipex.fd[0], pipex.fd[1]);
	the_closer(pipex.file1, pipex.file2);
	pipex.cmd = ft_split(argv[2], ' ');
	while (pipex.paths[pipex.i])
	{
		pipex.paths[pipex.i] = ft_strjoin(pipex.paths[pipex.i], "/");
		pipex.paths[pipex.i] = ft_strjoin(pipex.paths[pipex.i], pipex.cmd[0]);
		if (access(pipex.paths[pipex.i], X_OK) == 0)
		{
			if (execve(pipex.paths[pipex.i], pipex.cmd, envp) == -1)
				ft_perror("ERROR");
		}
		pipex.i++;
	}
	ft_error("command not found1\n");
}

void	secondchild(t_pipex pipex, char **envp, char **argv)
{
	dup2(pipex.fd[0], 0);
	dup2(pipex.file2, 1);
	the_closer(pipex.fd[0], pipex.fd[1]);
	the_closer(pipex.file1, pipex.file2);
	pipex.cmd = ft_split(argv[3], ' ');
	while (pipex.paths[pipex.i])
	{
		pipex.paths[pipex.i] = ft_strjoin(pipex.paths[pipex.i], "/");
		pipex.paths[pipex.i] = ft_strjoin(pipex.paths[pipex.i], pipex.cmd[0]);
		if (access(pipex.paths[pipex.i], X_OK) == 0)
		{
			if (execve(pipex.paths[pipex.i], pipex.cmd, envp) == -1)
				ft_perror("ERROR");
		}
		pipex.i++;
	}
	ft_error("command not found2\n");
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		p;

	p = 0;
	if (argc != 5)
		ft_error("invalid arguments\n");
	//--------------------------------------------------
	pipex.file1 = open(argv[1], O_RDONLY);
	if (pipex.file1 == -1)
		ft_error(" file not found\n");
	pipex.file2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (pipex.file2 == -1)
		ft_error(" file not found\n");
	//--------------------------------------------------
	pathfinder(&pipex, envp);
	if (pipe(pipex.fd) == -1)
		ft_error("cannot creat pipe\n");
	pipex.k = fork();
	if (pipex.k == 0)
		firstchild(pipex, envp, argv);
	pipex.r = fork();
	if (pipex.r == 0)
		secondchild(pipex, envp, argv);
	the_closer(pipex.file1, pipex.file2);
	the_closer(pipex.fd[0], pipex.fd[1]);
	waitpid(pipex.k, NULL, 0);
	waitpid(pipex.r, NULL, 0);
}
