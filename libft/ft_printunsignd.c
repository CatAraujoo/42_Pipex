/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:33:58 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:32:27 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunsignd(unsigned int nb, int fd)
{
	int		count;
	char	c;

	count = 0;
	if (nb > 9)
		count += ft_printunsignd((nb / 10), fd);
	c = (nb % 10) + '0';
	write (fd, &c, 1);
	count++;
	return (count);
}
