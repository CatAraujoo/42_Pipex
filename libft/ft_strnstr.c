/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:39:45 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/06 11:13:02 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *b, const char *s, size_t size)
{
	size_t	i;
	size_t	f;

	if (s[0] == '\0')
		return ((char *)b);
	i = 0;
	while (b[i] != '\0')
	{
		f = 0;
		while (s[f] != '\0' && b[i + f] == s[f] && (i + f) < size)
			f++;
		if (s[f] == '\0')
			return ((char *)b + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char b[] = "hello im catarina";
	char s[] = "im cat";

	printf ("%s", ft_strnstr(b, s, 12));

}*/
