#include <signal.h>
#include <unistd.h>
#include "ft_printf.h"

void	signal_handler(int signum)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	c = c << 1;
	if (signum == SIGUSR2)
		c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", c);
		c = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();
	return (0);
}
