/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:10:41 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/06 09:56:07 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
/*
#include <stdio.h>
int	main(void)
{
	char dest[] = "Hello";
	char src[] = "world";

	printf ("dest: %s\n",dest);
	printf ("src: %s\n", src);
	ft_memcpy(dest, src, 1);
	printf ("after dest: %s\n", dest);
	printf ("after src: %s", src);
//sizeof(src)
}*/
