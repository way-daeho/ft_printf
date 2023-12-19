/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:04:20 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/19 16:07:11 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dectochar(int addr, int *flag_sum);

int	format_d(va_list ap)
{
	int	flag_sum;
	int	flag;
	int	addr;

	flag_sum = 0;
	addr = va_arg(ap, int);
	if (addr == -2147483648)
	{
		flag = write(1, "-2147483648", 11);
		if (flag == -1)
			return (-1);
		return (flag);
	}
	flag = dectochar(addr, &flag_sum);
	if (flag == -1)
		return (-1);
	return (flag_sum);
}

static int	dectochar(int addr, int *flag_sum)
{
	char	*decimal;

	decimal = "0123456789";
	if (addr < 0)
	{
		addr *= -1;
		if (write(1, "-", 1) == -1)
			return (-1);
		*flag_sum += 1;
	}
	if (addr / 10 != 0)
	{
		if (dectochar(addr / 10, flag_sum) == -1)
			return (-1);
	}
	if (write(1, &decimal[addr % 10], 1) == -1)
		return (-1);
	else
		*flag_sum += 1;
	return (0);
}
