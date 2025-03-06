/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:43:34 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/04 14:31:39 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d > s)
	{
		while (size--)
		{
			d[size] = s[size];
		}
	}
	else
	{
		ft_memcpy(d, s, size);
	}
	return (dest);
}
/*
#include <stdio.h>
int	main(void)
{
	char dest[] = "Helloo";
	char src[] = "world";

	printf ("Before memmove\n%s\n%s\n", dest, src);
	ft_memmove(dest, src, 6);
	printf ("After memmove\n%s\n%s", dest, src);
}*/
