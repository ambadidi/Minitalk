#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n < -9)
			ft_putnbr(-(n / 10));
		ft_putchar(-(n % 10) + 48);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}

int main(int argc, char **argv)
{
	pid_t pid;

	pid = getpid();
	ft_putnbr(pid);
    ft_putchar('\n');
    // signal(SIGUSR2, your fonc);
    // signal(SIGUSR1, your fonc);
    while (1)
    {
        pause();
    }

	
	
	return (0);
}