/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 09:17:44 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/06 10:51:17 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	d = ft_strlen(dest);
	if (size <= d)
	{
		return (ft_strlen(src) + size);
	}
	s = 0;
	while (src[s] != '\0' && size > (d + 1))
	{
		dest[d] = src[s];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char dest[] = "a";
	const char src[] = "lorem";
	
	printf ("%zu\n", ft_strlcat(dest, src, 15));
	printf ("%s", dest);
	//printf ("\n%zu", ft_strlcat(dest, src, 15));

}*/