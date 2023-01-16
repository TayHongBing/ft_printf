/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:48:41 by thong-bi          #+#    #+#             */
/*   Updated: 2022/12/09 15:23:47 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	len;

	i = 0;
	if (s != NULL)
		len = ft_strlen(s);
	if (s != NULL && f != NULL)
	{
		while (i < len)
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
