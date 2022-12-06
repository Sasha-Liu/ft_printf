/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsliu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:14:22 by hsliu             #+#    #+#             */
/*   Updated: 2022/12/06 12:50:44 by hsliu            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		add;

	count = 0;
	add = 0;
	va_start(ap, fmt);
	ft_print(ap, fmt, &count, &add);
	va_end(ap);
	return (count);
}

int	ft_print(va_list ap, char *fmt, int *count, int *add)
{
	while (*fmt)
	{
		if (*fmt != '%')
			*add = write(1, fmt, 1);
		else
		{
			fmt++;
			if (*fmt == 'c' || *fmt == 'd' || *fmt == 'i')
				*add = ft_print_int(va_arg(ap, int), *fmt);
			else if (*fmt == 's' || *fmt == 'p')
				*add = ft_print_ptr(va_arg(ap, void *), *fmt);
			else if (*fmt == 'u' || *fmt == 'x' || *fmt == 'X')
				*add = ft_print_unsigned(va_arg(ap, unsigned int), *fmt);
			else if (*fmt == '%')
				*add = write(1, "%", 1);
			else
				return (-1);
		}
		if (*add < 0)
			return (-1);
		*count = *count + *add;
		fmt++;
	}
	return (*count);
}
