/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:25:32 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/03/06 13:42:29 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	ft_parent_process(char **av, int *fd, char **envp);
void	ft_child_process(char **av, int *fd, char **envp);
void	execute(char *av, char **envp, int *fd);
char	*ft_find_path(char *cmd, char **envp);
void	ft_free_str(char **str);
void	ft_exit(char *msg);

#endif