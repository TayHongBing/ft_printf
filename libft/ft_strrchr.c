/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:24:35 by thong-bi          #+#    #+#             */
/*   Updated: 2022/12/14 15:40:48 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		last = (char *)&s[i];
	return (last);
}

/*
int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = 'z';
   char *ret;
   char *ret1;

   ret = ft_strrchr(str, ch);
   ret1 = strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   printf("String after |%c| is - |%s|\n", ch, ret1);
   
   return(0);
} */