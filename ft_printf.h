/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:52:22 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/06 12:49:03 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

int	ft_printf(char *fmt, ...);
int	ft_print(va_list ap, char *fmt, int *count, int *add);
int	ft_print_int(int n, char c);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_print_ptr(void *p, char c);
int	ft_putstr(char *s);
int	ft_puthex(unsigned long m);
int	ft_print_unsigned(unsigned int n, char c);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_x_low(unsigned int n);
int	ft_putnbr_x_upp(unsigned int n);

#endif
