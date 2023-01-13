/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:49:02 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/09 15:24:44 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_first_flag(char flag)
{
	if (flag == '-' || (flag >= '0' && flag <= '9') || flag == '.' || flag == '*')
		return (1);
	return ;
}

int	ft_print_width(char c, int width)
{
	int	i;

	i = -1;
	while (++i < width)
		write(1, c, 1);
	return (i);
}

int	ft_print_all(char flag, t_print tab, va_list args)
{
	int	res;

	res = 0;
	if (flag == 'c')
		res = ft_print_char(tab, args);
	else if (flag == 's')
		res = ft_printstr(tab, args);
	else if (flag == 'p')
		res = ft_printptr(tab, args);
	else if (flag == 'd' || flag == 'i')
		res = ft_printnbr(tab, args);
	else if (flag == 'u')
		res = ft_printunsigned(tab, args);
	else if (flag == 'x')
		res = ft_printhex(HEXLOW, tab, args);
	else if (flag == 'X')
		res = ft_printhex(HEXUP, tab, args);
	else if (flag == '%')
		res = ft_printpercent(tab);
	return (res);
}
