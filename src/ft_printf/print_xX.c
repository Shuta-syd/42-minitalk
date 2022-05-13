/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:43:46 by shogura           #+#    #+#             */
/*   Updated: 2022/05/13 13:43:52 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flag_sharp(t_status **status, char *x, int flag, unsigned int num)
{
	if ((*status)->sharp && !flag && num != 0)
	{
		(*status)->width -= 2;
		(*status)->ret += ft_putstr(x);
		return (0);
	}
	else if ((*status)->sharp && flag && num != 0)
	{
		(*status)->width -= 2;
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		(*status)->ret += ft_putstr(x);
		return (0);
	}
	return (1);
}

static void	print_no_precision(t_status **status, unsigned int num,
					char *base, char *literal)
{
	if ((*status)->minus)
	{
		print_flag_sharp(status, literal, 0, num);
		ft_putnbr_base(num, 16, base);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else if ((*status)->zero)
	{
		print_flag_sharp(status, literal, 0, num);
		(*status)->ret += ft_putnchar('0', (*status)->width);
		ft_putnbr_base(num, 16, base);
	}
	else
	{
		print_flag_sharp(status, literal, 0, num);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		ft_putnbr_base(num, 16, base);
	}
}

static void	print_is_precision(t_status **status, unsigned int num,
				char *base, char *literal)
{
	int	digits;

	digits = get_digits(num, 16);
	if ((*status)->minus)
	{
		print_flag_sharp(status, literal, 0, num);
		(*status)->ret += ft_putnchar('0', (*status)->precision - digits);
		ft_putnbr_base(num, 16, base);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else
	{
		if (print_flag_sharp(status, literal, 1, num))
			(*status)->ret += ft_putnchar(' ', (*status)->width);
		(*status)->ret += ft_putnchar('0', (*status)->precision - digits);
		ft_putnbr_base(num, 16, base);
	}
}

int	print_x(t_status *status, va_list *ap)
{
	int				digits;
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	digits = get_digits_ul(num, 16);
	status->ret += digits;
	if (status->precision > digits && num != 0)
		status->width -= status->precision;
	else
		status->width -= digits;
	if (status->precision)
		print_is_precision(&status, num, "0123456789abcdef", "0x");
	else
		print_no_precision(&status, num, "0123456789abcdef", "0x");
	return ((int)status->ret);
}

int	print_X(t_status *status, va_list *ap)
{
	int				digits;
	unsigned int	num;

	num = va_arg(*ap, unsigned int);
	digits = get_digits_ul(num, 16);
	status->ret += digits;
	if (digits > status->precision)
		status->width -= digits;
	else if (status->precision > digits)
		status->width -= status->precision;
	if (status->precision)
		print_is_precision(&status, num, "0123456789ABCDEF", "0X");
	else
		print_no_precision(&status, num, "0123456789ABCDEF", "0X");
	return ((int)status->ret);
}
