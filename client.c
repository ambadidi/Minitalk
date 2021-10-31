#include "minitalk.h"



int	ft_atoi(const char *str)
{
	size_t		i;
	long int	res;
	long int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		if (res >= 4294967296)
			return ((sign > 0) ? -1 : 0);
		i++;
	}
	return (res * sign);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}
void    send_msg(int pid_server, char *msg)
{
	int bit;
	int len;
	int i;

	i = 0;
	len = ft_strlen(msg);
	while (i <= len)
	{
		bit = 0;
		while (bit < 8)
		{
			if ((msg[i] >> bit) & 1)
				kill(pid_server, SIGUSR2);
			else
				kill(pid_server, SIGUSR1);
			bit++;
			usleep(100);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	int pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (1);
	else
		send_msg(pid, argv[2]);
	return (0);
}