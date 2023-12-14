/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:04:20 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/14 19:29:47 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dectochar(int addr, int *sign, int *flag, int *flag_sum);

int	format_d(int addr)
{
	int	flag_sum;
	int	flag;
	int	sign;

	sign = 1;
	flag_sum = 0;
	flag = dectochar(addr, &sign, &flag, &flag_sum);
	if (flag == -1)
		return (-1);
	if (sign == -1)
		return (flag_sum + 1);
	return (flag_sum);
}

int	dectochar(int addr, int *sign, int *flag, int *flag_sum)
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
