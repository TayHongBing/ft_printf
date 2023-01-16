/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:43:36 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/16 17:04:30 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_width_nbr(t_print tab, int len, int num)
{
	int	count;

	count = 0;
	if (tab.zero)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			count ++;
		}
		count += ft_print_width('0', tab.wid - len);
	}
	else if (tab.prec >= len)
	{
		if (num < 0)
			count += ft_print_width(' ', tab.wid - tab.prec - 1);
		else
			count += ft_print_width(' ', tab.wid - tab.prec);
	}
	else
		count += ft_print_width(' ', tab.wid - size);
	return (count);
}

int print_prec_nbr(t_print tab, int len, int num)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	if (num < 0 && tab.prec < len && !tab.zero)
	{
		write(1, "-", 1);
		return (1);
	}
	if (tab.prec > 0)
	{
		if (num < 0)
		{
			write(1, "-", 1);
			count++;
			i--;
		}
		while (i++ < tab.prec - len)
		{
			write(1,"0", 1);
			count++;
		}
	}
	return (count);
}

int	check_dash_nbr(t_print tab, int len, char *str, int num)
{
	int	count;
	if (num < 0)
		str++;
	if (tab.dash)
	{
		count += print_prec_nbr(tab, len, num);
		count += ft_putstr_fd(str, 1);
		count += print_width_nbr(tab, len, num);
	}
	else if (!tab.dash)
	{
		count += print_width_nbr(tab, len, num);
		count += print_prec_nbr(tab, len, num);
		count += ft_putstr_fd(str, 1);
	}
	return (count);
}
int	ft_printnbr(t_print tab, va_list args)
{
	int		num;
	char	*str;
	int		len;
	int		res;

	num = va_arg(args, int);
	str = ft_itoa(num);
	len = ft_strlen(str);
	res = 0;
	if (tab.zero && (tab.dash || tab.prec >= 0))
		tab.zero = 0;
	if (tab.prec == 0 && *str == '0')
	{
		res += ft_print_width(' ', tab.wid);
		return (res);
	}
	res += check_dash_nbr(tab, len, str, num);
	free (str);
	return (res);
}