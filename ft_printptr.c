/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:18:52 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/16 18:12:22 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned long long num, int len)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		num /= len;
		count++;
	}
	return (count);
}

char	*ft_convert_ptr(char *array, unsigned long long num)
{
	int		len_hex;
	int		len_num;
	char	*str;

	len_hex = ft_strlen(array);
	len_num = ft_num_len(num, len_hex);
	str = (char *)malloc(sizeof(char) * (len_num + 1));
	if (!str)
		return (NULL);
	str[len_num] = '\0';
	while (--len_num)
	{
		str[len_num] = array[num % len_hex];
		num /= len_hex;
	}
	if (len_num == 0)
		str[len_num] = array[num % len_hex];
	return (str);
}

int	check_dash_ptr(t_lst tab, int len, char *str)
{
	int	count;

	count = 0;
	if (tab.dash)
	{
		count += ft_putstr_fd("0x", 1);
		count += ft_putstr_fd(str, 1);
		count += ft_print_width(' ', tab.wid - (len + 2));
	}
	else if (!tab.dash)
	{
		count += ft_print_width(' ', tab.wid - (len + 2));
		count += ft_putstr_fd("0x", 1);
		count += ft_putstr_fd(str, 1);
	}
	return (count);
}

int	ft_printptr(t_lst tab, va_list args)
{
	char				*str;
	int					len;
	int					res;
	unsigned long long	num;

	num = va_arg(args, unsigned long long);
	res = 0;
	if (!num)
	{
		if (!tab.prec)
			str = ft_strdup("");
		else
			str = ft_strdup("0");
	}
	else
		str = ft_convert_ptr("0123456789abcdef", num);
	len = ft_strlen(str);
	res += check_dash_ptr(tab, len, str);
	free(str);
	return (res);
}
