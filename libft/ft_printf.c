/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:32:15 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/02/12 15:31:45 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_format(va_list args, const char form)
{
	int	i;

	i = 0;
	if (form == 'c')
		i = ft_printchar(va_arg(args, int));
	else if (form == 's')
		i = ft_printstr(va_arg(args, char *));
	else if (form == 'p')
		i = ft_printptr(va_arg(args, unsigned long));
	else if (form == 'd' || form == 'i')
		i = ft_printnbr((long)va_arg(args, int), 1);
	else if (form == 'u')
		i = ft_printunsignd((long)va_arg(args, unsigned int), 1);
	else if (form == 'x' || form == 'X')
		i = ft_printhexa((long)va_arg(args, unsigned int), form, i);
	else
		i = ft_printchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int			i;
	va_list		args;
	int			len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] != 0)
				len += ft_format(args, s[i]);
		}
		else
		{
			len += ft_printchar(s[i]);
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int main(void)
{
    const char c[] = " %";
    char a = 'a';
    unsigned int nb = 587;
    int i = -15;
    unsigned long h = 42;
    
    ft_printf("string: %s\n", c);
    ft_printf("char: %c\n", a);
    ft_printf("int: %i\n", i);
    ft_printf("unsign: %u\n", nb);
    ft_printf("hexa: %x\n", h);//2a
    ft_printf("HEXA: %X\n", h);//2A
    ft_printf("ptr: %p\n", nb);
}*/
