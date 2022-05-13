/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:43:46 by shogura           #+#    #+#             */
/*   Updated: 2022/05/13 13:43:43 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(t_status *status, va_list *ap)
{
	uintptr_t	address;

	address = va_arg(*ap, uintptr_t);
	status->ret += get_digits_ul(address, 16);
	status->width -= get_digits_ul(address, 16) + 2;
	if (status->minus)
	{
		status->ret += ft_putstr("0x");
		ft_putnbr_base(address, 16, "0123456789abcdef");
		status->ret += ft_putnchar(' ', status->width);
	}
	else
	{
		status->ret += ft_putnchar(' ', status->width);
		status->ret += ft_putstr("0x");
		ft_putnbr_base(address, 16, "0123456789abcdef");
	}
	return ((int)status->ret);
}
