#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "Señal recibida: SIGUSR1\n", 26);
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	printf("PID del servidor: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
