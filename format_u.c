/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:33:17 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/19 15:57:17 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dectochar(unsigned int addr, int *flag_sum);

int	format_u(va_list ap)
{
	int				flag_sum;
	int				flag;
	unsigned int	addr;

	flag_sum = 0;
	addr = va_arg(ap, unsigned int);
	flag = dectochar(addr, &flag_sum);
	if (flag == -1)
		return (-1);
	return (flag_sum);
}

static int	dectochar(unsigned int addr, int *flag_sum)
{
	char	*decimal;

	decimal = "0123456789";
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
