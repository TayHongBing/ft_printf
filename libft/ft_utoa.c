/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:41:40 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/19 16:52:12 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int num)
{
	char	*n;
	int		len;

	len = num_len(num);
	n = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	n[len] = '\0';
	while (num != 0)
	{
		n[len - 1] = num % 10 + 48;
		num /= 10;
		len--;
	}
	return (n);
}