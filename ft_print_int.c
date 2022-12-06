/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:15:38 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/06 11:28:34 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//print char or integer, depending on the char c
//return -1 on error
int	ft_print_int(int n, char c)
{
	if (c == 'c')
		return (ft_putchar((char)n));
	return (ft_putnbr(n));
}
