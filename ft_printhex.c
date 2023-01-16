/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:40:46 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/16 15:57:06 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prec_hex(t_print tab, int len)
{
	int	i;
	
	if (tab.prec)
	{
		i = -1;
		while (++i < tab.prec - len)
			ft_putchar_fd('0', 1);
		return (i);
	}
	return (0);
}

int	print_width_hex(t_print tab, int len)
{
	int	count;

	count = 0;
	if (tab.zero && !tab.dash && tab.prec < 0)
		count = ft_print_width('0', tab.wid - len);
	else if (tab.prec >= len)
		count = ft_print_width(' ', tab.wid - tab.prec);
	else
		count = ft_print_width(' ', tab.wid - len);
	return (count);
}

int	check_dash_hex(t_print tab, int len, char *str)
{
	int	count;
	
	count = 0;
	if (tab.dash)
	{
		count += print_prec_hex(tab, len);
		ft_putstr_fd(str, 1);
		count += len;
		count += print_width_hex(tab, len);
	}
	else if (!tab.dash)
	{
		count += print_width_hex(tab, len);
		count += print_prec_hex(tab, len);
		ft_putstr_fd(str, 1);
		count += len;
	}
	return (count);
}

int	ft_printhex(char *array, t_print tab, va_list args)
{
	char	*str;
	int		len;
	int		res;
	unsigned int	num;

	res = 0;
	num = va_arg(args, unsigned int);
	if (!num)
		str = ft_strdup("0");
	else
		str = ft_convert_ptr(array, num);
	len = ft_strlen(str);
	if (tab.prec == 0 && str[0] == '0')
	{
		res += ft_print_width(' ', tab.wid);
		return (res);
	}
	res += check_dash_hex(tab, len, str);
	free(str);
	return (res);
}
