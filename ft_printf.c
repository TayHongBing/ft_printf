/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                  		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:49:02 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/19 16:10:23 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	res;

	res = 0;
	if (format == 'c')
		res += ft_print_char(va_arg(args, int));
	else if (format == 's')
		res += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		res += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		res += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		res += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		res += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		res += ft_printpercent();
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		res;

	i = 0;
	res = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			res += ft_formats(args, format[i + 1]);
			i++;
		}
		else
			res += ft_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (res);
}
