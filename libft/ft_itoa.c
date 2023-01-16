/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:31:14 by thong-bi          #+#    #+#             */
/*   Updated: 2022/12/14 15:39:27 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count++;
		nbr /= 10;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static int	absolute(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;

	length = len(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	str[length--] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n == -2147483648)
	{
		str[length--] = '8';
		n /= 10;
	}
	if (n < 0)
		str[0] = '-';
	while (n != 0)
	{
		str[length] = '0' + absolute(n % 10);
		n /= 10;
		length--;
	}
	return (str);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483648));
// 	return 0;
// }
