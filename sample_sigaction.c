#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int count;

void	handler(int signal)
{
	count += 100;
	printf("this is signal action\n");
	return;
}

int main(int argc, char const *argv[])
{
	struct sigaction sa;

	if (sigemptyset(&sa.sa_mask) == -1)
	{
		printf("emptyset error");
		exit(1);
	}
	sa.sa_handler = handler;
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		printf("sigaction() error");
		exit(1);
	}
	while (count < 50){}
	printf("end");
	return 0;
}

/*
struct sigaction {
void (*sa_handler)(int);
void (*sa_sigaction)(int, siginfo_t *, void *);
sigset_t sa_mask;
int sa_flags;
void (*sa_restorer)(void);
};
*/
