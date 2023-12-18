/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:33:17 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/18 17:44:18 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	dectochar(unsigned int addr, int *flag, int *flag_sum);

int	format_u(va_list ap)
{
	int				flag_sum;
	int				flag;
	unsigned int	addr;

	flag_sum = 0;
	addr = va_arg(ap, unsigned int);
	flag = dectochar(addr, &flag, &flag_sum);
	if (flag == -1)
		return (-1);
	return (flag_sum);
}

static int	dectochar(unsigned int addr, int *flag, int *flag_sum)
{
	char	*decimal;

	decimal = "0123456789";
	if (*flag == -1)
		return (-1);
	if (addr / 10 != 0)
		dectochar(addr / 10, flag, flag_sum);
	*flag = write(1, &decimal[addr % 10], 1);
	if (*flag == -1)
		return (-1);
	*flag_sum += *flag;
	return (0);
}
