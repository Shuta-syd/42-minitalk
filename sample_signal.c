#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void	sig_usr(int signo)
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGUSR2)
		printf("received SIGUSR2\n");
	else
		printf("received signal %d\n", signo);
}

int main(void)
{
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("cannot catch SIGUSR1");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("cannot catch SIGUSR2");
	while (1)
	{
	}
}
