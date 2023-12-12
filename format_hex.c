/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:51:20 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/12 17:45:19 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex(unsigned int addr, int xX, int *flag, int *flag_sum);

int	format_x(va_list ap, int xX)
{
	unsigned int	addr;
	int				flag_sum;
	int				flag;

	addr = va_arg(ap, unsigned int);
	flag_sum = 0;
	flag = hex(addr, xX, &flag, &flag_sum);
	if (flag == -1)
		return (-1);
	return (flag_sum + 2);
}

int	hex(unsigned int addr, int xX, int *flag, int *flag_sum)
{
	char	*shex;
	char	*bhex;

	shex = "0123456789abcdef";
	bhex = "0123456789ABCDEF";
	if (addr / 16 != 0)
		hex(addr / 16, xX, flag, flag_sum);
	if (xX == 1)
		*flag = write(1, &shex[addr % 16], 1);
	else
		*flag = write(1, &bhex[addr % 16], 1);
	if (*flag == -1)
		return (-1);
	*flag_sum += *flag;

	return (0);
}
