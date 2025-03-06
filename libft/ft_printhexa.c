/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:01:22 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:32:01 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_printhexa(unsigned long n, const char t, int count)
{
	char	*base_m;
	char	*base;

	base_m = "0123456789ABCDEF";
	base = "0123456789abcdef";
	if (n >= 16)
	{
		count = ft_printhexa(n / 16, t, count);
	}
	if (t == 'x')
	{
		count += ft_printchar(base[n % 16]);
	}
	else if (t == 'X')
	{
		count += ft_printchar(base_m[n % 16]);
	}
	return (count);
}

/*
int main(void)
{
    unsigned long n = 12397;//=7b
    unsigned long m = 321;//=141
	int i = 0;
    
    ft_printhexa(n, 'x', i);
    write (1, "\n", 1);
    ft_printhexa(m, 'x', i);
    write (1, "\n", 1);
}*/