/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:25:34 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/11 21:25:37 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	format_c(va_list ap)
// {
// 	int		flag;
// 	char	ch;

// 	ch = va_arg(ap, int);
// 	flag = write(1, &ch, 1);
// 	if (flag == -1)
// 		return (-1);
// 	else
// 		return (flag);
// }

int	format_c(char ap)
{
	int		flag;

	flag = write(1, &ap, 1);
	if (flag == -1)
		return (-1);
	else
		return (flag);
}

// int	format_s(va_list ap)
// {
// 	int		s_len;
// 	int		flag;
// 	char	*s;

// 	s = va_arg(ap, char *);
// 	s_len = cal_len(s);

// 	flag = 0;
// 	while (*s)
// 	{
// 		flag = write(1, s, 1);
// 		if (flag == -1)
// 			return (-1);
// 		s++;
// 	}
// 	return (s_len);
// }

int	format_s(char *ap)
{
	int		flag;
	int		flag_sum;

	flag = 0;
	flag_sum = 0;
	while (*ap)
	{
		flag = write(1, ap, 1);
		flag_sum += flag;
		if (flag == -1)
			return (-1);
		ap++;
	}
	return (flag_sum);
}
