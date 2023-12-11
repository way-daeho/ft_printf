/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:39:51 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/11 20:59:19 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *container, ...)
{
	va_list	va_ptr;

	va_start(va_ptr, container);
	while (*container)
	{
		if (*container != '%')
			write(1, container, 1);
		container++;
	}

	return (0);
}

int	cal_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
