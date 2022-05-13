/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:37:41 by shogura           #+#    #+#             */
/*   Updated: 2022/05/13 17:50:51 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

void	rev_success(int signum)
{
	(void)signum;
	ft_printf("success in sending the letters\n");
	exit(0);
}

void	send_char(pid_t pid, char ch)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (kill(pid, ((ch >> i) & 1) + SIGUSR1))
		{
			ft_printf("Failed to send signal");
			exit(1);
		}
		usleep(300);
		i--;
	}
	usleep(200);
}

int	main(int argc, char const *argv[])
{
	size_t	i;
	pid_t	pid;

	i = 0;
	if (signal(SIGUSR1, rev_success))
		exit(1);
	if (argc != 3 || ft_isdigit_num(argv[1]))
	{
		ft_printf("Usage: ./client [PID] [String]");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf("pid is 0");
		exit(1);
	}
	while (argv[2][i])
		send_char(pid, argv[2][i++]);
	send_char(pid, EOT);
	while (1)
		pause();
	return (0);
}
