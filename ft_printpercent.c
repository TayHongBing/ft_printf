/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpercent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:54:33 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/14 17:54:33 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpercent(t_print tab)
{
	int	res;

	res = 0;
	if (tab.dash == 1)
	{
		ft_putchar_fd('%', 1);
		res += ft_print_width(' ', tab.wid - 1)
	}
	else if (tab.dash == 0)
	{
		if (tab.zero == 1)
			res += ft_print_width('0', tab.wid - 1);
		else
			res += ft_print_width(' ', tab.wid - 1);
		ft_putchar_fd('%', 1);
	}
	return (res + 1);
}
