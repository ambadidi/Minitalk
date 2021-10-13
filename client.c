#include <signal.h>

void    send_msg(int pid_server, char *msg)
{
	int bit;
	int len;
	int i;

	i = 0;
	len = ft_stren(msg);
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