/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:53:45 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/04 14:56:52 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *dest, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)dest;
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char str[] = "hello";

	ft_bzero(str, 5);
	printf ("%s", str);
	int 	i = 0;
	while (i < 5)
		printf ("%d", str[i++]);
}*/
