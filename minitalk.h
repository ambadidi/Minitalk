#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <limits.h>
#include <sys/types.h>

int	ft_strlen(const char *str);
int	ft_atoi(const char *str);
void    send_msg(int pid_server, char *msg);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	receive_msg(int sig);
void    send_msg(int pid_server, char *msg);

#endif