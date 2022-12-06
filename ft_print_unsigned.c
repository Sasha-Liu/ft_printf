/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:00:31 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/06 13:09:31 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//print u x X depending on c
int	ft_print_unsigned(unsigned int n, char c)
{
	if (c == 'u')
		return (ft_putnbr_unsigned(n));
	if (c == 'x')
		return (ft_putnbr_x_low(n));
	else
		return (ft_putnbr_x_upp(n));
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 9)
		count = count + ft_putchar('0' + n);
	else
	{
		count = count + ft_putnbr_unsigned(n / 10);
		count = count + ft_putchar('0' + n % 10);
	}
	return (count);
}

int	ft_putnbr_x_low(unsigned int n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n <= 15)
		count = count + ft_putchar(hex[n]);
	else
	{
		count = count + ft_putnbr_x_low(n / 16);
		count = count + ft_putchar(hex[n % 16]);
	}
	return (count);
}

int	ft_putnbr_x_upp(unsigned int n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n <= 15)
		count = count + ft_putchar(hex[n]);
	else
	{
		count = count + ft_putnbr_x_upp(n / 16);
		count = count + ft_putchar(hex[n % 16]);
	}
	return (count);
}
