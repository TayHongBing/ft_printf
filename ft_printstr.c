/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:38:23 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/14 16:38:23 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prec_str(char *str, int len, t_print tab)
{
	int	i;

	i = 0;
	if (tab.prec >= 0 && tab.prec >= len)
	{
		while (str[i++])
			ft_putchar_fd(str[i], 1);
	}
	else if (tab.prec >= 0 && tab.prec < len)
	{
		while (i++ < tab.prec)
			ft_putchar_fd(str[i], 1);
	}
	else
	{
		while (str[i++])
			ft_putchar_fd(str[i], 1);
	}
	return (i);
}

int	check_prec(char *str, int len, t_print tab)
{
	int	i;

	i = 0;
	if (tab.prec >= 0 && tab.prec >= len)
	{
		while (str[i])
			i++;
	}
	else if (tab.prec >= 0 && tab.prec < len)
	{
		while (i < tab.prec)\
			i++;
	}
	else
	{
		while (str[i])
			i++;
	}
	return (i);
}

int	check_dash(char *str, int len, t_print tab)
{
	int	res;
	int	prec;

	res = 0;
	prec = check_prec(str, len, tab);
	if (!tab.dash && tab.wid > prec)
	{
		if (tab.zero == 1)
			res += ft_print_width('0', tab.wid - prec);
		else
			res += ft_print_width(' ', tab.wid - prec);
		res += print_prec_str(str, len, tab);
	}
	else if (tab.dash && tab.wid > prec)
	{
		res += print_prec_str(str, len, tab);
		res += ft_print_width(' ', tab.wid - prec);
	}
	else
		res += print_prec_str(str, len, tab);
	return (res);
}

int	ft_printstr(t_print tab, va_list args)
{
	char	*str;
	int		len;
	int		res;

	res = 0;
	if (!(str = va_arg(args, char *)))
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	res += check_dash(str, len, tab);
	return (res);
}
