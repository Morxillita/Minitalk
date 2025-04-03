#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	send_char(int pid, char c)
{
	int	i = 7;

	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2); // bit 1
		else
			kill(pid, SIGUSR1); // bit 0
		usleep(100); // Espera un poco para que el server no se pierda señales
		i--;
	}
}
