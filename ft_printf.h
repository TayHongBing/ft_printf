/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:59:51 by thong-bi          #+#    #+#             */
/*   Updated: 2023/01/19 16:16:19 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_formats(va_list args, const char format);
int	ft_print_char(int c);
int	ft_printstr(char *str);
int	ft_printptr(unsigned long ptr);
int	ft_printnbr(int n);
int	ft_printunsigned(unsigned int n);
int	ft_printhex(unsigned int num, const char format);
int	ft_printpercent(void);
int	ft_ptr_len(unsigned long num);

#endif
