/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:24:10 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:32:16 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printptr(unsigned long p)
{
	int	len;

	len = 0;
	if (!p)
	{
		ft_printstr("(nil)");
		return (5);
	}
	else
	{
		ft_printstr("0x");
		len += ft_printhexa(p, 'x', len);
	}
	return (len + 2);
}
/*
int main(void)
{
    unsigned long p = 5;

    ft_printptr(p);
    write (1, "\n", 1);
}*/