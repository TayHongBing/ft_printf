/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:59:51 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/16 18:23:16 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef	struct s_lst
{
	int		wid;		//width
	int		prec;		//precision
	int		zero;		//zero padding
	int		pnt;		//.
	int		dash;		//-
} t_lst;

# define HEXUP	"0123456789ABCDEF"
# define HEXLOW	"0123456789abcdef"

int	ft_print_char(t_lst tab, va_list args);
int	ft_printstr(t_lst tab, va_list args);
int	ft_printnbr(t_lst tab, va_list args);
int	ft_printpercent(t_lst tab);
char	*ft_convert_ptr(char *array, unsigned long long num);
int	ft_printptr(t_lst tab, va_list args);
int	ft_printhex(char *array, t_lst tab, va_list args);
int	ft_printunsigned(t_lst tab, va_list args);
int	ft_print_width(char c, int width);
int	ft_print_all(char flag, t_lst tab, va_list args);
int	ft_first_flag(char flag);
int	ft_print_other_flag(char flag, t_lst tab);
int	ft_printf(const char *str, ...);

#endif
