/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:11:46 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/10/24 11:50:37 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *) s + i);
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *) s + i);
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "Hello world";
	int c = 'H';

	printf ("%s", ft_strchr(str, c));
}*/
