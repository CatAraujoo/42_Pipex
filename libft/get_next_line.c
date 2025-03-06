/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:24:57 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/02/14 15:11:48 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *s)
{
	char	*buff;
	char	*temp;
	ssize_t	bytes;

	if (!s)
		s = ft_strdup("");
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(s), NULL);
	bytes = 1;
	while (!ft_strchr(s, '\n') && bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (free(buff), free(s), NULL);
		buff[bytes] = '\0';
		temp = ft_strjoin(s, buff);
		if (!temp)
			return (free(buff), free(s), NULL);
		free(s);
		s = temp;
	}
	free(buff);
	return (s);
}

char	*print_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*print_rest(char *s)
{
	int		i;
	int		j;
	char	*new_s;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	new_s = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1));
	if (!new_s)
		return (free(s), NULL);
	i++;
	j = 0;
	while (s[i])
		new_s[j++] = s[i++];
	new_s[j] = '\0';
	free(s);
	return (new_s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = read_file(fd, s);
	if (!s)
		return (free(s), NULL);
	line = print_line(s);
	s = print_rest(s);
	return (line);
}

/* int main (void)
{
	int fd;
    char *line = NULL;

    // Abre o arquivo em modo leitura
    fd = open("file1.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erro ao abrir o arquivo");
        return (1);
    }

    // Lê e imprime cada linha
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
		free(line);
    }
    // Fecha o arquivo
    close(fd);
    return (0);
}  */