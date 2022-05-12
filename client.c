/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shogura <shogura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:22:33 by shogura           #+#    #+#             */
/*   Updated: 2022/05/11 19:36:57 by shogura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// send to sever
#include "client.h"
static int check = 0;

void signal_handler(int signum, siginfo_t *info, void *content)
{
	write(1, "1", 1);
}

int main(int argc, char *argv[]) //server pid | string to send
{
	pid_t	pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_putstr("Usage: ./client [PID] [String]");
		exit(1);
	}
	pid = ft_atoi(argv[1]); //PID string to ini
	sigemptyset(&sa.sa_mask); // sa_mask -> シグナルハンドラ実行中に禁止 (block) するシグナルのマスク
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	int i = 6;
	while (i-- > 0)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}

	return 0;
	}
