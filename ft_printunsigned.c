/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:15:33 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/19 16:52:02 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int num)
{
	int		res;
	char	*n;

	res = 0;
	if (num == 0)
		res += write(1, "0", 1);
	else
	{
		n = ft_utoa(num);
		res += ft_printstr(n);
		free(n);
	}
	return (res);
}
