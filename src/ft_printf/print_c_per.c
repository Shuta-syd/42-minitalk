/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_per.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:43:23 by shogura           #+#    #+#             */
/*   Updated: 2022/05/12 16:51:23 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c_per(t_status *status, va_list *ap, char type)
{
	char	ch;

	if (type == '%')
		ch = '%';
	else
		ch = va_arg(*ap, int);
	status->width -= 1;
	if (status->minus)
	{
		status->ret += ft_putnchar(ch, 1);
		status->ret += ft_putnchar(' ', status->width);
	}
	else
	{
		status->ret += ft_putnchar(' ', status->width);
		status->ret += ft_putnchar(ch, 1);
	}
	return ((int)status->ret);
}
