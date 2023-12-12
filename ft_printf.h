/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:10 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/12 16:23:23 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *container, ...);
// int	format_c(va_list ap);
int	format_c(char ap);
// int	format_p(va_list ap);
// int	format_p(int *a);
int	cal_len(const char *str);
// int	format_s(va_list ap);
int	format_s(char *s);
// int	format_d(int d);
// int	format_x(va_list ap, int xX);
int	format_x(int d, int xX);
#endif