/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:43:48 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/10/28 10:16:53 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*pt;

	if (n == 0 || size == 0)
	{
		return (malloc(0));
	}
	pt = (void *)malloc(n * size);
	if (!pt)
	{
		return (NULL);
	}
	ft_bzero(pt, n * size);
	return (pt);
}
/*
#include <stdio.h>

int	main(void)
{
	int* ptr;
	int n, i;
	
	n = 0;
	printf("Enter number of elements: %d\n", n);
	ptr = (int*)calloc(n, sizeof(int));

	if (ptr == NULL)
	{
        	printf("Memory not allocated.\n");
        	exit(0);
    	}
    	else
	{
        	printf("Memory successfully allocated using calloc.\n");
        	for (i = 0; i < n; ++i)
		{
            		ptr[i] = i + 1;
        	}

        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i)
	{
        	printf("%d, ", ptr[i]);
        }
    	}
    	return 0;
}*/
