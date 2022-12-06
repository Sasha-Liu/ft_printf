/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:40:27 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/06 11:30:20 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//print a string or a pointer depends on c
int	ft_print_ptr(void *p, char c)
{
	unsigned long	m;

	if (c == 's' && p == NULL)
		return (ft_putstr("(null)"));
	if (c == 's')
		return (ft_putstr((char *)p));
	m = (unsigned long)p;
	ft_putstr("0x");
	return (ft_puthex(m) + 2);
}

//print pointer in hexdecimal
int	ft_puthex(unsigned long m)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";	
	count = 0;
	if (m < 16)
		count = count + ft_putchar(hex[m]);
	else
	{
		count = count + ft_puthex(m / 16);
		count = count + ft_putchar(hex[m % 16]);
	}
	return (count);
}
