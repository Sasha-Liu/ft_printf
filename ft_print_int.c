/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:15:38 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/05 16:55:08 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c);
int	ft_putnbr(int n);

//print char or integer, depending on the char c
//return -1 on error
int	ft_print_int(int n, char c)
{
	if (c == 'c')
		return (ft_putchar((char)n));
	return (ft_putnbr(n));
}

int	ft_putnbr(int n)
{
	int count;
	
	count = 0;
	if (n == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count = count + ft_putchar('-');
		n = -n;
	}
	if (n <= 9)
		count = count + ft_putchar('0' + n);
	else
	{
		count = count + ft_putnbr(n / 10);
		count = count + ft_putchar('0' + n % 10);
	}
	return (count);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
