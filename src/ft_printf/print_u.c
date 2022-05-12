/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:42:03 by shogura           #+#    #+#             */
/*   Updated: 2022/05/12 16:51:35 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_is_precision(t_status **status, unsigned int num, int digits)
{
	if ((*status)->minus)
	{
		(*status)->ret += ft_putnchar('0', (*status)->precision - digits);
		ft_putnbr_base(num, 10, "0123456789");
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		(*status)->ret += ft_putnchar('0', (*status)->precision - digits);
		ft_putnbr_base(num, 10, "0123456789");
	}
}

static void	print_no_precision(t_status **status, unsigned int num)
{
	if ((*status)->minus)
	{
		ft_putnbr_base(num, 10, "0123456789");
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else if ((*status)->zero)
	{
		(*status)->ret += ft_putnchar('0', (*status)->width);
		ft_putnbr_base(num, 10, "0123456789");
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		ft_putnbr_base(num, 10, "0123456789");
	}
}

int	print_u(t_status *status, va_list *ap)
{
	int				digits;
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	digits = get_digits_ul(num, 10);
	status->ret += digits;
	if (digits > status->precision)
		status->width -= digits;
	else if (status->precision > digits)
		status->width -= status->precision;
	if (status->precision)
		print_is_precision(&status, num, digits);
	else
		print_no_precision(&status, num);
	return ((int)status->ret);
}
