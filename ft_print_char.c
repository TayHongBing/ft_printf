/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:24:43 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/16 18:28:30 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(t_lst tab, va_list args)
{
	if (tab.dash == 1 && tab.wid > 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ft_print_width(' ', tab.wid - 1);
		return (tab.wid);
	}
	else if (tab.dash == 0 && tab.wid > 1)
	{
		if (tab.zero == 1)
			ft_print_width('0', tab.wid - 1);
		else
			ft_print_width(' ', tab.wid - 1);
	}
	ft_putchar_fd(va_arg(args, int), 1);
	if (tab.wid > 1)
		return (tab.wid);
	return (1);
}
