#include "minitalk.h"

int	ft_atou(char *str)
{
		int	res;

		res = 0;
		while (*str)
				res = (*(str++) - '0') + (res * 10);
		return (res);
}

void	ft_print_bite(int pid, char c)
{
		int i;

		i = 0;
		while (i < 8)
		{
				if ((c & (1 << i++)))
						kill(pid, SIGUSR1);
				else
						kill(pid, SIGUSR2);
				usleep(300);
		}
}


int	main(int ac, char **av)
{
		if (ac == 3)
				while (*av[2])
						ft_print_bite(ft_atou(av[1]), *(av[2]++));
		else
				write(2, "\033[31mError. Wrong number of arguments\n\033[0m", 40);
		return (0);
}
