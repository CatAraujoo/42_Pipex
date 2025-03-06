/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:38:32 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/03/06 14:46:17 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *av, char **envp, int *fd)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(av, ' ');
	path = ft_find_path(cmd[0], envp);
	if (!path)
	{
		ft_free_str(cmd);
		close(fd[0]);
		close(fd[1]);
	}	
	if (execve(path, cmd, envp) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	ft_free_str(cmd);
	free(path);
}

char	*ft_find_path(char *cmd, char **envp)
{
	char	**full_path;
	char	*part_path;
	char	*path;
	int		i;
	
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	full_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (full_path[i])
	{
		part_path = ft_strjoin(full_path[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_free_str(full_path), path);
		free(path);
		i++;
	}
	ft_free_str(full_path);
	return (0);
}

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}
