/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:15:33 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/16 16:24:26 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_width_unsign(int len, t_print tab)
{
	int	count;

	count = 0;
	if (tab.zero && !tab.dash && tab.prec <= 0)
		count += ft_print_width('0', tab.wid - len);
	else if (tab.prec >= len)
		count += ft_print_width(' ', tab.wid - tab.prec);
	else
		count += ft_print_width(' ', tab.wid - len);
	return (count);
}

int	print_prec_unsign(int len, t_print tab)
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

int	check_dash_unsign(char *str, int len, t_print tab)
{
	int	count;

	count = 0;
	if (tab.dash)
	{
		count += print_prec_unsign(len, tab);
		ft_putstr_fd(str, 1);
		count += len;
		count += print_width_unsign(len, tab);
	}
	else if (!tab.dash)
	{
		count += print_width_unsign(len, tab);
		count += print_prec_unsign(len, tab);
		ft_putstr_fd(str, 1);
		count += len;
	}
	return (count);
}

int	ft_num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		len /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int num)
{
	char	*n;
	int		len;

	len = ft_num_len(num);
	n = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	n[len] = '\0';
	while (len-- > 0)
	{
		n[len - 1] = num % 10 + 48;
		num /= 10;
	}
	return (n);
}

int	ft_printunsigned(t_print tab, va_list args)
{
	char	*str;
	int		len;
	int		res;

	str = ft_utoa(va_arg(args, unsigned int));
	len = ft_strlen(str);
	res = 0;
	if (tab.prec == 0 && str[0] == '0')
	{
		res += ft_print_width(' ', tab.wid);
		return (res);
	}
	res += check_dash_unsign(str, len, tab);
	free(str);
	return (res);
}
