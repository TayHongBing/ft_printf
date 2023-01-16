/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:35:24 by thong-bi          #+#    #+#             */
/*   Updated: 2022/12/14 15:40:21 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *str, char c)
{
	int	count;
	int	trig;

	count = 0;
	trig = 0;
	while (*str)
	{
		if (*str != c && trig == 0)
		{
			trig = 1;
			count++;
		}
		else if (*str == c)
			trig = 0;
		str++;
	}
	return (count);
}

static char	*word_dup(char const *s, int end, int start)
{
	char	*store;
	int		i;

	i = 0;
	store = malloc((end - start + 1) * sizeof(char));
	if (!store)
		return (0);
	while (start < end)
		store[i++] = s[start++];
	store[i] = '\0';
	return (store);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	j;
	int		trig;

	i = 0;
	j = 0;
	trig = -1;
	arr = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && trig < 0)
			trig = i;
		else if ((s[i] == c || i == ft_strlen(s)) && trig >= 0)
		{
			arr[j++] = word_dup(s, i, trig);
			trig = -1;
		}
		i++;
	}
	arr[j] = 0;
	return (arr);
}

// int  main()
// {
// 	int		index = 0;
// 	char *str = "      split       this for   me  !       ";
// 	char charset = ' ';
// 	char **split;

// 	split = ft_split(str, charset);

// 	while (split[index])
// 	{
// 		printf("tab[%d]: $%s$\n", index, split[index]);
// 		printf ("\n");
// 		index++;
// 	}

// 	free (split);
// 	return (0);
// }