/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:04:20 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/15 22:30:18 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dectochar(int addr, int *sign, int *flag, int *flag_sum);

int	format_d(va_list ap)
{
	int	flag_sum;
	int	flag;
	int	sign;
	int	addr;

	sign = 1;
	flag_sum = 0;
	addr = va_arg(ap, int);
	flag = dectochar(addr, &sign, &flag, &flag_sum);
	if (flag == -1)
		return (-1);
	if (sign == -1)
		return (flag_sum + 1);
	return (flag_sum);
}

static int	dectochar(int addr, int *sign, int *flag, int *flag_sum)
{
	char	*decimal;

	decimal = "0123456789";
	if (addr == -2147483648)
	{
		*flag = write(1, "-2147483648", 12);
		if (*flag == -1)
			return (-1);
		*flag_sum = 12;
		return (0);
	}
	if (addr < 0)
	{
		*sign *= -1;
		addr *= (*sign);
		*flag = write(1, "-", 1);
	}
	if (addr / 10 != 0)
		dectochar(addr / 10, sign, flag, flag_sum);
	*flag = write(1, &decimal[addr % 10], 1);
	if (*flag == -1)
		return (-1);
	*flag_sum += *flag;
	return (0);
}
