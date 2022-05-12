/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:11:26 by shogura           #+#    #+#             */
/*   Updated: 2022/05/12 18:02:08 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# define EOT 4
typedef struct s_data
{
	int		n;
	char	ch;
	pid_t	pid;
}	t_data;

int	ft_printf(const char *format, ...);
#endif
