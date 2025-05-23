#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		write(1, "✅ Señal SIGUSR1 recibida\n", 26);
	else if (signum == SIGUSR2)
		write(1, "✅ Señal SIGUSR2 recibida\n", 26);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	printf("PID del servidor: %d\n", getpid());

	while (1)
		pause();
	return (0);
}
