/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:59:51 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/16 17:06:33 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

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

int	ft_print_char(t_print tab, va_list args);
int	ft_printstr(t_print tab, va_list args);
int	ft_printnbr(t_print tab, va_list args);
int	ft_printpercent(t_print tab);
char	*ft_convert_ptr(char *array, unsigned long long num);
int	ft_printptr(t_print tab, va_list args);
int	ft_printhex(char *array, t_print tab, va_list args);
int	ft_printunsigned(t_print tab, va_list args);
int	ft_print_width(char c, int width);
int	ft_print_all(char flag, t_print tab, va_list args);
int	ft_first_flag(char flag);

#endif
