/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:12:51 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/10/31 10:27:46 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*s;
	char	*b;
	char	*e;

	if (!str || !set)
		return (0);
	b = (char *)str;
	e = b + ft_strlen(str);
	while (*b && ft_find_set(*b, set))
		++b;
	while (b < e && ft_find_set(*(e - 1), set))
		--e;
	s = ft_substr(b, 0, e - b);
	return (s);
}
/*
#include <stdio.h>

int main(void)
{
    char s[] = "olamola";
    char set[] = "ola";
    printf ("%s", ft_strtrim(s, set));
}*/
