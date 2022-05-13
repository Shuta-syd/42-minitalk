/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:06:56 by shogura           #+#    #+#             */
/*   Updated: 2022/05/13 01:06:01 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <inttypes.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdbool.h>
typedef struct s_status
{
	long long	sharp;
	long long	plus;
	long long	minus;
	long long	zero;
	long long	space;
	long long	width;
	long long	precision;
	long long	ret;
}	t_status;

size_t	ft_strlen(const char *s);;
int		get_digits(long long num, int base);
int		get_digits_ul(size_t num, int base);
int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);
int		ft_putstr(char const *s);
int		ft_putnchar(int ch, int len);
int		ft_putnstr(char const *s, int n);
void	ft_putnbr(int n);
void	ft_putnbr_base(size_t n, size_t base, char *base_s);
int		scan_format(const char **format, t_status *status, va_list *ap);
int		print_d_i(t_status *status, va_list *ap);
int		print_u(t_status *status, va_list *ap);
int		print_s(t_status *status, va_list *ap, char *null);
int		print_x(t_status *status, va_list *ap);
int		print_X(t_status *status, va_list *ap);
int		print_c_per(t_status *status, va_list *ap, char type);
int		print_p(t_status *status, va_list *ap);
int		print_flag_sharp(t_status **status, char *x,
			int flag, unsigned int num);
#endif
