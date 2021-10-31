#include "minitalk.h"

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

void	receive_msg(int sig)
{
	static int	size;
	static char	to_print;

	to_print += ((sig % 2) << size);
	size++;
	if (size == 8)
	{
		ft_putchar(to_print);
		if (!to_print)
			ft_putchar('\n');
		to_print = 0;
		size = 0;
	}
}

int main()
{
	pid_t pid;

	pid = getpid();
	ft_putnbr(pid);
    ft_putchar('\n');
    
    while (1)
    {
		signal(SIGUSR2, receive_msg);
	    signal(SIGUSR1, receive_msg);
        pause();
    }

	
	
	return (0);
}