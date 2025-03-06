/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:34:02 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/04 10:06:57 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_nb(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	char			*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_count_nb(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len] = '\0';
	while (n != 0)
	{
		s[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (s);
}
/*
#include <stdio.h>
int main(void)
{
    int n = 0;

    printf ("%s\n", ft_itoa(n));
}*/
