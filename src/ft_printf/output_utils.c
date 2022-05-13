/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:24:50 by shogura           #+#    #+#             */
/*   Updated: 2022/05/13 13:43:34 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnchar(int ch, int len)
{
	int	tmp;

	tmp = len;
	if (len < 0)
		return (0);
	while (len--)
		write(1, &ch, 1);
	return (tmp);
}

int	ft_putstr(char const *s)
{
	int	len;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_putnstr(char const *s, int n)
{
	int	ret;

	ret = 0;
	if (s == NULL || n < 0)
		return (0);
	while (*s && ret < n)
	{
		ret++;
		ft_putnchar(*s++, 1);
	}
	return (ret);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("2147483648");
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n >= 0)
		ft_putnchar(n + '0', 1);
	return ;
}

void	ft_putnbr_base(size_t n, size_t base, char *base_s)
{
	if (n >= base)
	{
		ft_putnbr_base(n / base, base, base_s);
		ft_putnchar(base_s[n % base], 1);
	}
	else if (0 <= n && n <= 15)
		ft_putnchar(base_s[n], 1);
	return ;
}
