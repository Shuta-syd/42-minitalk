/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:22:39 by shogura           #+#    #+#             */
/*   Updated: 2022/05/11 19:33:46 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

// receive from client signal
void receiver(int signum, siginfo_t *info, void *content)
{
	write(1, "2", 1);
	kill(info->si_pid, SIGUSR1);
	return;
}

int main(void)
{
	struct sigaction sa;

	sa.sa_sigaction = &receiver;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr(getpid());
	ft_putchar('\n');
	while (1)
		pause();
}
