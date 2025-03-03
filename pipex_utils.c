/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:38:32 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/03/03 15:27:07 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close_fd(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	ft_free_str(char **str)
{
	int	i;
	
	i = 0;
	while (*str[i])
		free(str[i]);
	free(str);
}

void	ft_exit(int error)
{
	if (error == 1)
	{
		ft_putstr_fd("Invalid input. It should ./pipex file1 cmd1 cmd2 file2.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (error == 2)
	{
		ft_putstr_fd("Failed to open file.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (error == 3)
	{
		ft_putstr_fd("Pipe creation failed.\n", 2);
		exit(EXIT_FAILURE);
	}
	if (error == 4)
	{
		ft_putstr_fd("Fork failed.\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	ft_open(char *file, int input_output)
{
	int	value;

	if (input_output == 0)
		value = open(file, O_RDONLY, 0444);
	if (input_output == 1)
		value = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (value);
}

char	*ft_get_path(char *cmd, char **env)
{
	int	i;
	char	**full_path;
	char	*part_path;
	char	*path;

	i = 0;
	if (!env[i])
		return (NULL);
	while (ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	full_path = ft_split(env[i] + 5, ":");
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
	return (NULL);
}