/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:15:33 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/05 22:15:33 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

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

char	*ft_itoa(unsigned int num)
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
		n[len - 1] = n % 10 + 48;
		n /= 10;
	}
	return (n);
}

int	ft_printunsigned(unsigned int num)
{
	int		len;
	char	*n;

	len = 0;
	if (num == 0)
		len += write(1, "0", 1);
	else
	{
		n = ft_itoa(num);
		len += ft_printstr(n);
		free (n);
	}
	return (len);
}
