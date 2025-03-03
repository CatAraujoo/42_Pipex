/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:08:34 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/03/03 15:26:46 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//create files
void	ft_execute(char *cmd, char **env, int *fd)
{
	char	**x_cmd;
	char	path;

	x_cmd = ft_split(cmd, ' ');
	path = get_path(x_cmd[0], env);
	if (!path || execve(path, x_cmd, env) < 0)
	{
		ft_free_str(x_cmd);
		ft_close_fd(fd);
		ft_exit("Error. Command not found.");
		exit(EXIT_FAILURE);
	}
	ft_free_str(x_cmd);
	free(path);
}

void	ft_child_process(char **av, int *pip, char **env)
{
	int	fd;

	close(pip[0]);
	fd = open(av[1], O_RDONLY, 0444);
	if (fd < 0)
	{
		close(pip[1]);
		ft_exit(4);
	}
	dup2(pip[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pip[1]);
	close(fd);
	ft_execute(av[2], env, pip);
}

void	ft_parent_process(char **av, int *pip, char **env)
{
	int	fd;

	close(pip[1]);
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		close(pip[0]);
		exit(EXIT_FAILURE);
	}
	dup2(pip[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pip[0]);
	close(fd);
	ft_execute(av[3], env, pip);
}
int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		ft_exit(1);
	if (pipe(fd) < 0)
		ft_exit(3);
	pid = fork();
	if (pid == -1)
		ft_exit(4);
	if (pid == 0)
		ft_child_process(av, fd, env);
	else
		ft_parent_process(av, fd, env);
	return (0);
}