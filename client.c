#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *s)
{
	int	i;
	int	res;
	int	segno;

	i = 0;
	res = 0;
	segno = 1;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v'
		|| s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			segno = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * segno);
}

void	signal_sender(pid_t spid, unsigned char s)
{
	unsigned char	temp;
	int				i;

	i = 8;
	temp = s;
	while (i > 0)
	{
		i--;
		temp = s >> i;
		if (temp % 2 == 0)
			kill(spid, SIGUSR2);
		else
			kill(spid, SIGUSR1);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	pid_t	spid;
	int		i;

	if (argc != 3)
		exit(0);
	spid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		signal_sender(spid, argv[2][i]);
		i++;
	}
	signal_sender(spid, 0);
	return (0);
}
