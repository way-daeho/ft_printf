/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:10 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/19 16:05:45 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *container, ...);
int	format_c(va_list ap);
int	format_s(va_list ap);
int	format_d(va_list ap);
int	format_x(va_list ap, int xX);
int	format_p(va_list ap);
int	format_u(va_list ap);
#endif