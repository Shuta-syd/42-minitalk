/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:31:25 by shogura           #+#    #+#             */
/*   Updated: 2022/05/13 23:00:16 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	get_digits(long long num, int base)
{
	int	digits;

	digits = 1;
	while (num / base != 0)
	{
		num /= base;
		digits++;
	}
	return (digits);
}

int	get_digits_ul(size_t num, int base)
{
	int	digits;

	digits = 1;
	while (num / base != 0)
	{
		num /= base;
		digits++;
	}
	return (digits);
}

static int	ft_overflow(int minus)
{
	if (minus > 0)
		return ((int)LONG_MAX);
	return ((int)LONG_MIN);
}

int	ft_atoi(const char *str)
{
	int			minus;
	size_t		i;
	long long	num;

	i = 0;
	num = 0;
	minus = 1;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = 10 * num + (str[i] - '0');
		if (num > LONG_MAX / 10 || (num == (LONG_MAX / 10)
				&& str[i] - '0' > (LONG_MAX % 10)))
			return (ft_overflow(minus));
		i++;
	}
	return ((int)num * minus);
}
