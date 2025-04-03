#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int pid = atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (0);
}
