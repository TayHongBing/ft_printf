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

/*typedef	struct s_print
{
	va_list	args;		//arg to print out
	int		wid;		//width
	int		prec;		//precision
	int		zero;		//zero padding
	int		pnt;		//.
	int		dash;		//-
	int		total;		//total_length (return value)
	int		sign;		//+ or - num
	int		is_zero;	//is number zero
	int		ptage;		//%
	int		sp;			//space flag
} t_print; */

int	ft_printchar(int c);
int	ft_printstr(char *str);
int	ft_printnbr(int n);
int	ft_printpercent(void);
int	ft_printptr(unsigned long ptr);
int	ft_printhex(unsigned int num, const char format);
int	ft_printunsigned(unsigned int num);

#endif
