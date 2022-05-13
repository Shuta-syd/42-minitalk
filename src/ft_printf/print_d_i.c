/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 20:29:39 by shogura           #+#    #+#             */
/*   Updated: 2022/05/13 13:43:40 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	scan_signs(t_status **status, int *num, int *minus_sign)
{
	if (*num < 0)
	{
		(*status)->plus = -1;
		*minus_sign = 1;
		if (*num != -2147483648)
			*num *= -1;
	}
	if (num < 0 || (*status)->plus || (*status)->space)
		(*status)->width--;
}

static void	print_sign(t_status **status, int minus_sign)
{
	if (minus_sign)
		(*status)->ret += ft_putnchar('-', 1);
	else if ((*status)->plus)
		(*status)->ret += ft_putnchar('+', 1);
	else if ((*status)->space)
		(*status)->ret += ft_putnchar(' ', 1);
}

static	void	print_no_precision(t_status **status, int num, int minus_sign)
{
	if ((*status)->minus)
	{
		print_sign(status, minus_sign);
		ft_putnbr(num);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else if ((*status)->zero)
	{
		print_sign(status, minus_sign);
		(*status)->ret += ft_putnchar('0', (*status)->width);
		ft_putnbr(num);
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		print_sign(status, minus_sign);
		ft_putnbr(num);
	}
}

static void	print_is_precision(t_status **status, int num,
				int minus_sign, int digits)
{
	if ((*status)->minus)
	{
		print_sign(status, minus_sign);
		(*status)->ret += ft_putnchar('0', (*status)->precision - digits);
		ft_putnbr(num);
		(*status)->ret += ft_putnchar(' ', (*status)->width);
	}
	else
	{
		(*status)->ret += ft_putnchar(' ', (*status)->width);
		print_sign(status, minus_sign);
		(*status)->ret += ft_putnchar('0', (*status)->precision - digits);
		ft_putnbr(num);
	}
}

int	print_d_i(t_status *status, va_list *ap)
{
	int	num;
	int	digits;
	int	minus_sign;

	minus_sign = 0;
	num = va_arg(*ap, int);
	if (status->precision == -1 && num == 0)
		return ((int)status->ret);
	scan_signs(&status, &num, &minus_sign);
	digits = get_digits(num, 10);
	status->ret += digits;
	if (digits > status->precision)
		status->width -= digits;
	else if (status->precision > digits)
		status->width -= status->precision;
	if (status->precision)
		print_is_precision(&status, num, minus_sign, digits);
	else
		print_no_precision(&status, num, minus_sign);
	return ((int)status->ret);
}
