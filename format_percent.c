/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:47:14 by daehlee           #+#    #+#             */
/*   Updated: 2023/12/12 17:47:56 by daehlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_percent(va_list ap)
{
	int		flag;
	char	ch;

	ch = va_arg(ap, char);
	flag = 0;
	flag = write(1, &ch, 1);
	if (flag == -1)
		return (-1);
	else
		return (flag);
}
