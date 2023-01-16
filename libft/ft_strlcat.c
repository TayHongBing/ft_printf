/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:01:51 by thong-bi          #+#    #+#             */
/*   Updated: 2022/10/13 17:29:01 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	i = 0;
	j = 0;
	if (!dstsize && !dst)
		return (ft_strlen(src));
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize > ft_strlen((const char *)dst))
	{
		while (dst[i] != '\0')
			i++;
		while (src[j] != '\0' && j < dstsize - dlen - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (dlen + slen);
	}
	else
		return (slen + dstsize);
}

// int	main()
// {
// 	char dst[30];
// 	char *src = (char *) "AAAAAAAAA";
// 	memset(dst, 'B', 4);
// 	printf("%s, %zu", dst, ft_strlcat(dst, src, 6));
// }