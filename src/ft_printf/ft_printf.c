/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:07:10 by shogura           #+#    #+#             */
/*   Updated: 2022/05/13 13:43:27 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	error_func(t_status *status, va_list *ap)
{
	if (status == NULL)
	{
		va_end(*ap);
		return (0);
	}
	va_end(*ap);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int			tmp;
	int			ret;
	va_list		ap;
	t_status	status;

	tmp = 0;
	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		status = (t_status){};
		tmp = scan_format(&format, &status, &ap);
		if (tmp < 0)
			return (error_func(&status, &ap));
		ret += tmp;
		if (ret > INT_MAX)
			return (error_func(&status, &ap));
	}
	va_end(ap);
	return (ret);
}
