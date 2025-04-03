#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);  // Bit 1
		else
			kill(pid, SIGUSR1);  // Bit 0
		usleep(100); // Espera mínima para no saturar
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Uso: ./client <PID>\n", 21);
		return (1);
	}
	int pid = atoi(argv[1]);

	send_char(pid, 'A');
	return (0);
}
