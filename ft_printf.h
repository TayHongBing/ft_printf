/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thong-bi <thong-bi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:59:51 by thong-bi          #+#    #+#             */
/*   Updated: 2022/12/20 14:59:51 by thong-bi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef	struct s_print
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
}


#endif
