/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:10:36 by thong-bi          #+#    #+#             */
/*   Updated: 2022/12/20 15:10:36 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_initialise_tab(t_print *tab)
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

int	ft_printf(const char *format, ...)
{
	t_print	*tab;
	int		i;
	int		res;

	tab = (t_print*)malloc(sizeof(t_print));
	if(!tab)
		return (NULL);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = 0;
	res = 0;
	while(format[i++])
	{
		if(format[i] == '%')

	}

}
