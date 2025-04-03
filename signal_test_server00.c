#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

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
