/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbentale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 04:31:53 by zbentale          #+#    #+#             */
/*   Updated: 2023/01/13 06:42:34 by zbentale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	the_closer(int a, int b)
{
	close(a);
	close(b);
}

int	pathfinder(t_pipex *pipex, char **envp)
{
	int	x;

	pipex->i = 0;
	x = 0;
	while (envp[pipex->i])
	{
		if (ft_strncmp(envp[pipex->i], "PATH=", 5) == 0)
		{
			pipex->save = envp[pipex->i] + 5;
			break ;
		}
		x++;
		pipex->i++;
	}
	if (x != 6)
	{
		return (2);
	}
	pipex->paths = ft_split(pipex->save, ':');
	pipex->i = 0;
	return (0);
}

void	firstchild(t_pipex pipex, char **envp, char **argv)
{
	dup2(pipex.fd[1], 1);
	dup2(pipex.file1, 0);
	the_closer(pipex.fd[0], pipex.fd[1]);
	the_closer(pipex.file1, pipex.file2);
	pipex.cmd = ft_split(argv[2], ' ');
	// if (pipex.b == 2 && pipex.file1 > 0)
	// {
	// 	ft_error2("command not found155: ", pipex.cmd[0]);
	// 	exit(1);
	// }
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
	ft_error1("command not found1: ", pipex.cmd[0]);
}

void	secondchild(t_pipex pipex, char **envp, char **argv)
{
	dup2(pipex.fd[0], 0);
	dup2(pipex.file2, 1);
	the_closer(pipex.fd[0], pipex.fd[1]);
	the_closer(pipex.file1, pipex.file2);
	pipex.cmd = ft_split(argv[3], ' ');
	// if (pipex.b == 2)
	// {
	// 	ft_error2("command not found2: ", pipex.cmd[0]);
	// 	exit(127);
	// }
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
	ft_error2("command not found2: ", pipex.cmd[0]);
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;
	int		status;

	i = 0;
	if (argc != 5)
		ft_error3("invalid arguments\n");
	pipex.b = pathfinder(&pipex, envp);
	pipex.file1 = open(argv[1], O_RDONLY | 0644);
	if (pipex.file1 == -1 && pipex.b == 2)
	{
		ft_error2("no such file or directory: ", argv[1]);
		ft_error1("command not found2: ", argv[3]);
	}
	else if (pipex.file1 > 0 && pipex.b == 2)
	{
		ft_error2("command not found1: ", argv[1]);
		ft_error2("command not found2: ", argv[3]);
	}
	else if(pipex.file1 == -1)
		ft_error("no such file or directory: ", argv[1]);
	pipex.file2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex.file2 == -1)
		ft_error("no such file or directory: ", argv[4]);
	if (pipe(pipex.fd) == -1)
		ft_error3("cannot creat pipe\n");
	pipex.k = fork();
	if (pipex.k == 0)
		firstchild(pipex, envp, argv);
	if (pipex.r == 0)
		secondchild(pipex, envp, argv);
	the_closer(pipex.file1, pipex.file2);
	the_closer(pipex.fd[0], pipex.fd[1]);
	waitpid(pipex.k, NULL, 0);
	waitpid(pipex.r, NULL, 0);
	// else
	// {
	// 	pipex.r = fork();
	// 	if (pipex.r == 0)
	// 		secondchild(pipex, envp, argv);
	// 	else
	// 	{
	// 		the_closer(pipex.file1, pipex.file2);
	// 		the_closer(pipex.fd[0], pipex.fd[1]);
	// 		waitpid(pipex.k, NULL, 0);
	// 		waitpid(pipex.r, &status, 0);
	// 		if (WIFEXITED(status))
	// 			return (WEXITSTATUS(status));
	// 	}
	// }
    //free strjoin
}
