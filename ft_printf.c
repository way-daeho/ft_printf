/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:51 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/15 22:41:08 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_branch(const char container, va_list *ap);

int	ft_printf(const char *container, ...)
{
	va_list			ap;
	unsigned int	idx;
	int				return_len;
	int				total_len;

	idx = 0;
	total_len = 0;
	len = 0;
	va_start(ap, container);
	while (container[idx])
	{
		if (container[idx] == '%')
			idx++;
		len = format_branch(container[idx], &ap);
		if (len == -1)
			return (-1);
		else
		{
			idx++;
			total_len += len;
		}
	}
	return (total_len);
}

static int	format_branch(const char container, va_list *ap)
{
	int	len;

	len = 0;
	if (container == 'c')
		len = format_c(ap);
	else if (container == 's')
		len = format_s(ap);
	else if (container == 'd' || container == 'i')
		len = format_d(ap);
	else if (container == 'x')
		len = format_x(ap, 1);
	else if (container == 'X')
		len = format_x(ap, 2);
	else if (container == 'p')
		len = format_p(ap);
	else
		len = write(1, &container, 1);
	if (len == -1)
		return (-1);
	return (len);
}
