#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "Uso: ./client <PID> <1 o 2>\n", 29);
		return (1);
	}

	int	pid = atoi(argv[1]);
	int tipo = atoi(argv[2]);

	if (tipo == 1)
		kill(pid, SIGUSR1);
	else if (tipo == 2)
		kill(pid, SIGUSR2);
	else
		write(1, "Error: señal debe ser 1 o 2\n", 29);

	return (0);
}
