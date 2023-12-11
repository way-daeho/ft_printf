/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:47:20 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/11 21:16:18 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	dectohex(unsigned long long addr, int *first, int *flag, int *flag_sum);

// int	format_pointer(va_list ap)
// {
// 	unsigned long long	addr;
// 	int					flag;

// 	addr = (unsigned long long)(ap, void *);
// 	flag = dectohex(addr);

// 	return (flag);
// }

int	format_p(va_list ap)
{
	unsigned long long	addr;
	int					flag_sum;
	int					flag;
	int					first;

	addr = va_arg(ap, unsigned long long);
	first = 1;
	flag_sum = 0;
	flag = dectohex(addr, &first, &flag, &flag_sum);
	if (flag == -1)
		return (-1);
	return (flag_sum + 2);
}

int	dectohex(unsigned long long addr, int *first, int *flag, int *flag_sum)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (*first == 1)
	{
		*first = 0;
		*flag = write(1, "0x", 2);
		if (*flag == -1)
			return (-1);
	}
	if (addr / 16 != 0)
		dectohex(addr / 16, first, flag, flag_sum);
	*flag = write(1, &hex[addr % 16], 1);
	if (*flag == -1)
		return (-1);
	*flag_sum += *flag;

	return (0);
}
