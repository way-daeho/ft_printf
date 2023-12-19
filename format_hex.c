/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:51:20 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/19 16:07:36 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex(unsigned int addr, int xX, int *flag_sum);

int	format_x(va_list ap, int xX)
{
	int				flag_sum;
	int				flag;
	unsigned int	addr;

	flag_sum = 0;
	addr = va_arg(ap, unsigned int);
	flag = hex(addr, xX, &flag_sum);
	if (flag == -1)
		return (-1);
	return (flag_sum);
}

static int	hex(unsigned int addr, int xX, int *flag_sum)
{
	char	*shex;
	char	*bhex;
	int		flag;

	shex = "0123456789abcdef";
	bhex = "0123456789ABCDEF";
	if (addr / 16 != 0)
	{
		if (hex(addr / 16, xX, flag_sum) == -1)
			return (-1);
	}
	if (xX == 1)
		flag = write(1, &shex[addr % 16], 1);
	else
		flag = write(1, &bhex[addr % 16], 1);
	if (flag == -1)
		return (-1);
	*flag_sum += flag;
	return (0);
}
