/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:37:38 by shogura           #+#    #+#             */
/*   Updated: 2022/05/13 16:40:42 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	send_success(pid_t client_pid)
{
	kill(client_pid, SIGUSR1);
}

void	rev_char(int signum, siginfo_t *info, void *content)
{
	static t_data	data;

	(void)content;
	if (data.pid != info->si_pid)
		data = (t_data){0, 0, info->si_pid};
	data.ch = data.ch << 1 | (signum - 30);
	data.n++;
	if (data.n == 8)
	{
		if (data.ch == EOT)
			send_success(info->si_pid);
		else
		{
			write(1, &data.ch, 1);
			data = (t_data){};
		}
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("ProcessID -> [%d]\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = rev_char;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL))
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL))
		exit(1);
	while (1)
		pause();
	return (0);
}
