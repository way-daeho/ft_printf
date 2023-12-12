/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:51 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/12 19:39:45 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_branch(const char **container, va_list *va_ptr, int *return_len);

int	ft_printf(const char *container, ...)
{
	va_list	va_ptr;
	int		return_len;
	int		total_len;

	va_start(va_ptr, container);
	return_len = 0;
	while (*container)
	{
		total_len = format_branch(&container, &va_ptr, &return_len);
		container++;
	}
	if (total_len < 0)
		return (-1);
	return (total_len);
}

int	format_branch(const char **container, va_list *va_ptr, int *return_len)
{
	int	len;

	if (*container == '%')
	{
		container++;
		if (*container == 'c')
			len = format_c(va_ptr);
		else if (*container == 's')
			len = format_s(va_ptr);
		else if (*container == 'd')
			len = format_d(va_ptr);
		else if (*container == 'x')
			len = format_x (va_ptr, 1);
		else if (*container == 'X')
			len = format_x (va_ptr, 2);
		else if (*container == '%')
			len = format_percent(va_ptr);
		va_ptr++;
	}
	else
		len = write(1, &container, 1);
	if (len == -1)
		return (-1);
	return (return_len += len);
}
