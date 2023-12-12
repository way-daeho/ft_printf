/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:10 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/12 17:46:24 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
#include <stdio.h> // 테스트용 제출할 때 지우기

int	ft_printf(const char *container, ...);
int	format_c(va_list ap);
int	format_p(va_list ap);
int	format_s(va_list ap);
int	format_d(va_list ap);
int	format_x(va_list ap, int xX);
int	format_percent(va_list ap);
#endif