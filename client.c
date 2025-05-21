#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*msg;

	if (argc != 3)
	{
		ft_printf("Uso: ./client <PID> <mensaje>\n");
		return (1);
	}
	pid = atoi(argv[1]);
	msg = argv[2];
	i = 0;
	while (msg[i])
	{
		send_char(pid, msg[i]);
		i++;
	}
	send_char(pid, '\n');
	return (0);
}
