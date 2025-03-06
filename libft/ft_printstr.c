/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:01:55 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:32:21 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		return (ft_printstr("(null)"));
	}
	while (str[i] != '\0')
	{
		i = i + ft_printchar(str[i]);
	}
	return (i);
}
/*
#include <stdio.h>
int	main(void)
{
	char *n = NULL;

	ft_printstr(n);
	printf("\n%s\n", n);
}*/
