/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:22:39 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/05 13:15:38 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	f;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(sizeof(*s) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	f = 0;
	while (s[i])
	{
		if (i >= start && f < len)
		{
			sub[f++] = s[i];
		}
		i++;
	}
	sub[f] = '\0';
	return (sub);
}
/*
#include <stdio.h>
int main(void)
{
    const char str[] = "123456789";

    printf ("%s", ft_substr(str, 1, 7));
}*/