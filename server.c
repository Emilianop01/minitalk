#include <signal.h>
#include <unistd.h>

void	ft_putnbr_fd(int i, int fd)
{
	int	res;

	if (i == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (i < 0)
	{
		write(fd, "-", 1);
		i = -i;
	}
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	res = i % 10 + '0';
	write(fd, &res, 1);
}

void	signal_decrypt(int signal)
{
	static unsigned char	c;
	static int				i;

	c |= (signal == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	write(1, "SERVER PID : ", 13);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, signal_decrypt);
	signal(SIGUSR2, signal_decrypt);
	while (1)
		pause();
	return (0);
}
