/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:04:20 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/11 21:48:38 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dectochar(long long addr, int *sign, int *flag, int *flag_sum);

int	format_d(va_list ap)
{
	long long	addr;
	int			flag_sum;
	int			flag;
	int			sign;

	addr = va_arg(ap, long long);
	sign = 1;
	flag_sum = 0;
	flag = dectochar(addr, &sign, &flag, &flag_sum);
	if (flag == -1)
		return (-1);
	if (sign == -1)
		return (flag_sum + 1);
	return (flag_sum);
}

int	dectochar(long long addr, int *sign, int *flag, int *flag_sum)
{
	char	*decimal;

	decimal = "0123456789";
	if (addr < 0)
	{
		*sign *= -1;
		addr *= (*sign);
		*flag = write(1, "-", 1);
		if (*flag == -1)
			return (-1);
	}
	if (addr / 10 != 0)
		dectochar(addr / 10, sign, flag, flag_sum);
	*flag = write(1, &decimal[addr % 10], 1);
	if (*flag == -1)
		return (-1);
	*flag_sum += *flag;

	return (0);
}
