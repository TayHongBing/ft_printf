/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:47:15 by thong-bi          #+#    #+#             */
/*   Updated: 2022/12/14 15:40:43 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!len && !haystack)
		return (NULL);
	i = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i + j] != '\0' && haystack[i + j] == needle[j] && i
			+ j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
		}
		i++;
	}
	return (0);
}

// int main () {
//    const char haystack[20] = "TutorialsPoint";
//    const char needle[10] = "als";
//    char *ret;
//    char *ret1;

//    ret = ft_strnstr(haystack, needle, 9);
//    ret1 = strnstr(haystack, needle, 9);

//    printf("The substring is: %s\n", ret);
//    printf("The substring is: %s\n", ret1);

//    return(0);
// }