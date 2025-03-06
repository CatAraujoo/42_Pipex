/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:35:30 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/06 12:43:01 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*c;

	i = 0;
	c = malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
/*
#include <stdio.h>

char	to_upper(unsigned int a, char c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
    return (c);
}
int main(void)
{
    char *s = "hello";

    printf ("%s", ft_strmapi(s, to_upper));
}*/