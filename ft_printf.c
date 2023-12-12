/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:51 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/12 18:28:28 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_branch(const char **container, va_list *va_ptr);

int	ft_printf(const char *container, ...)
{
	va_list	va_ptr;
	int		total_len;

	va_start(va_ptr, container);
	total_len = format_branch(&container, &va_ptr);
	if (total_len == -1)
		return (-1);
	return (total_len);
}

int	format_branch(const char **container, va_list *va_ptr)
{
	int	len;
	int	return_len;

	return_len = 0;
	while (*container)
	{
		if (*container == '%')
		{
			container++;
			if (*container == 'c')
				return_len = format_c(va_ptr);
			else if (*container == 's')
				return_len = format_s(va_ptr);
			else if (*container == 'd')
				return_len = format_d(va_ptr);
			else if (*container == 'x')
				return_len = format_x (va_ptr, 1);
			else if (*container == 'X')
				return_len = format_x (va_ptr, 2);
			else if (*container == '%')
				return_len = format_percent(va_ptr);
		}
		else
			write(1, container, 1);
		container++;
		va_ptr++;
	}
}
