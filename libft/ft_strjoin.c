/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:43:14 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/05 13:15:30 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*s;
	size_t	i;
	size_t	f;

	i = 0;
	s = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!s)
		return (NULL);
	while (i < ft_strlen(str1))
	{
		s[i] = str1[i];
		i++;
	}
	f = 0;
	while (f < ft_strlen(str2))
	{
		s[i] = str2[f];
		i++;
		f++;
	}
	s[i] = '\0';
	return (s);
}
/*
#include <stdio.h>

int main (void)
{
    char s1[] = "Hello";
    char s2[] = "World";

    printf ("%s", ft_strjoin(s1, s2));
}*/