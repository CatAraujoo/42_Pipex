/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:08:34 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/03/06 14:13:39 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_process(char **av, int *fd, char **envp)
{
	int		infile;

	infile = open(av[1], O_RDONLY, 0444);
	if (infile == -1)
	{
		close(fd[1]);
		ft_exit("Error! Failed to open file.\n");
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], envp, fd);//executa o cmd1
}

void	ft_parent_process(char **av, int *fd, char **envp)
{
	int		outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC , 0644);
	if (outfile == -1)
	{
		close(fd[0]);
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	execute(av[3], envp, fd);//executa o cmd2
}

int		main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (!envp)
		ft_exit("Error! No environment variables.\n");
	if (ac == 5)
	{
		if (pipe(fd) < 0)
			ft_exit("Error! Failed to create pipe\n");
		pid = fork();
		if (pid == -1)
			ft_exit("Error! Fork failed.\n");
		else if (pid == 0)
			ft_child_process(av, fd, envp);
		else
			ft_parent_process(av, fd, envp);
	}
	ft_exit("Error! Invalid input. It should be: ./pipex file1 cmd1 cmd2 file2\n");
	return (0);
}