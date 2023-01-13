/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:59:51 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/09 15:55:35 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef	struct s_print
{
	int		wid;		//width
	int		prec;		//precision
	int		zero;		//zero padding
	int		pnt;		//.
	int		dash;		//-
} t_print;

# define HEXUP	"0123456789ABCDEF"
# define HEXLOW	"0123456789abcdef"

int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printnbr(int n);
int	ft_printpercent(void);
int	ft_printptr(unsigned long ptr);
int	ft_printhex(unsigned int num, const char format);
int	ft_printunsigned(unsigned int num);

#endif
