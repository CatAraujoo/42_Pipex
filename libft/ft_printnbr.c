/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:40:55 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:32:08 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nb, int fd)
{
	int		result;
	char	c;

	result = 0;
	c = 0;
	if (nb == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (nb < 0)
	{
		result += ft_printchar('-');
		nb = -nb;
	}
	if (nb > 9)
		result = result + ft_printnbr((nb / 10), fd);
	c = (nb % 10) + '0';
	result += ft_printchar(c);
	return (result);
}
/*
int	main(void)
{
	ft_printnbr(420, 1);
	return (0);
}*/