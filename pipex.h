/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:25:32 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/03/03 15:25:09 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define SUCCESS 0
# define FAILURE 1
# define WRONG_AC 2
# define WRONGPATH 3

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft/libft.h"

int				ft_open(char *file, int input_output);
char	*ft_get_path(char *cmd, char **env);
void	ft_child_process(char **av, int *pip, char **env);
void	ft_parent_process(char **av, int *pip, char **env);
void	ft_execute(char *cmd, char **env, int *fd);
void	ft_close_fd(int *fd);
void	ft_free_str(char **str);
void	ft_exit(int error);

#endif