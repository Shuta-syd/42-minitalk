/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:09:40 by shogura           #+#    #+#             */
/*   Updated: 2022/05/12 17:23:58 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include <signal.h>
# include <libc.h>
# include <unistd.h>
# define EOT 4
int	ft_isdigit_num(char const *nm);
int	ft_atoi(const char *str);
int	ft_printf(const char *format, ...);
#endif
