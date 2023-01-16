/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:10:36 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/16 18:31:33 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_lst	ft_initialise_tab(t_lst tab)
{
	tab.wid = 0;
	tab.prec = -1;
	tab.zero = 0;
	tab.pnt = 0;
	tab.dash = 0;
	return (tab);
}

t_lst	ft_check_wild(t_lst tab, va_list args)
{
	if (tab.pnt == 1)
		tab.prec = va_arg(args, int);
	else if (tab.wid < 1)
	{
		tab.wid = va_arg(args, int);
		if (tab.wid < 0)
		{
			tab.wid *= (-1);
			tab.dash = 1;
		}
	}
	return (tab);
}

t_lst	ft_first_check(const char *format, t_lst tab, va_list args)
{
	int	i;

	i = 0;
	while (format[i] && ft_first_flag(format[i]))
	{
		if (format[i] == '-')
			tab.dash = 1;
		else if (format[i] == '0' && tab.wid < 1 && tab.pnt == 0)
			tab.zero = 1;
		else if ((format[i] >= '0' && format[i] <= '9') && tab.pnt == 0)
			tab.wid = tab.wid * 10 + format[i] - 48;
		else if (format[i] == '.')
		{
			tab.pnt = 1;
			tab.prec = 0;
		}
		else if ((format[i] >= '0' && format[i] <= '9') && tab.pnt == 1)
			tab.prec = tab.prec * 10 + format[i] - 48;
		else if (format[i] == '*')
			tab = ft_check_wild(tab, args);
		i++;
	}
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	t_lst	tab;
	va_list	args;
	int		i;
	int		res;

	va_start(args, format);
	i = 0;
	res = 0;
	while (format[i] != '\0')
	{
		res += (format[i] == '%') ? 0 : 1;
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			tab = ft_initialise_tab(tab);
			tab = ft_first_check(&format[++i], tab, args);
			while (ft_first_flag(format[i]))
				i++;
			res += ft_print_all(format[i], tab, args);
		}
		else
			ft_putchar_fd(format[i], 1);
		i += (format[i] == '\0') ? 0 : 1;
	}
	va_end(args);
	return (res);
}
