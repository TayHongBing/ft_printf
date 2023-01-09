/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:10:36 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/09 15:57:15 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

/*t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wid = 0;
	tab->prec = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->sign = 0;
	tab->total = 0;
	tab->is_zero = 0;
	tab->dash = 0;
	tab->ptage = 0;
	tab->sp = 0;
	return (tab);
}
*/
int	ft_check_format(va_list args, const char format)
{
	int total;

	total = 0;
	if (format == 'c')
		total += ft_printchar(va_arg(args, int));
	else if (format == 's')
		total += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		total += ft_printptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		total += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		total += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		total += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		total += ft_printpercent();
	return (total);
}

int	ft_printf(const char *format, ...)
{
	//t_print	*tab;
	va_list	args;
	int		i;
	int		res;

	//tab = (t_print*)malloc(sizeof(t_print));
	//if(!tab)
	//	return (0);
	//ft_initialise_tab(tab);
	va_start(args, format);
	i = 0;
	res = 0;
	while(format[i++])
	{
		if(format[i] == '%')
			res += ft_check_format(args, format[i + 1]);
		else	
			res += write(1, &format[i], 1);
	}
	va_end(args);
	//res += tab->total;
	//free (tab);
	return (res);
}
