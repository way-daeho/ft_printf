/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:25:34 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/18 17:27:53 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_c(va_list ap)
{
	int		flag;
	int		temp;
	char	ch;

	temp = va_arg(ap, int);
	ch = temp;
	flag = write(1, &ch, 1);
	if (flag == -1)
		return (-1);
	else
		return (flag);
}

int	format_s(va_list ap)
{
	int		flag;
	int		flag_sum;
	char	*s;

	flag = 0;
	flag_sum = 0;
	s = va_arg(ap, char *);
	if (s == NULL)
		s = "(null)";
	while (*s)
	{
		flag = write(1, s, 1);
		flag_sum += flag;
		if (flag == -1)
			return (-1);
		s++;
	}
	return (flag_sum);
}
