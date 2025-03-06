/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:40:19 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/06 10:53:18 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	if (n < 1)
	{
		return (0);
	}
	while (i < n && s1[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	if (s1[i] < s2[i] || s1[i] > s2[i])
	{
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "test\200";
	char	str2[] = "test\0";

	printf ("%d", ft_strncmp(str1, str2, 6));
}*/