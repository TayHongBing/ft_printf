/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:18:52 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/19 16:54:52 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_put_ptr(unsigned long num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + 48), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long ptr)
{
	int	res;

	res = 0;
	res += write(1, "0x", 2);
	if (ptr == 0)
		res += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		res += ft_ptr_len(ptr);
	}
	return (res);
}
