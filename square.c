#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "map_data.h"

#define BUFFER_SIZE 1024

int	ft_check_spaces(char c)
{
	if (c == '\n' || c == '\t' || c == '\f'
		|| c == '\r' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr_base;

	i = 0;
	sign = 1;
	nbr_base = 0;
	while (ft_check_spaces(str[i]) == 1)
	{
		i++;
	}
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr_base = 10 * nbr_base + (str[i] - '0');
		i++;
	}
	return (nbr_base * sign);
}


void read_file(char *name)
{
    int fd = open(name, O_RDONLY);
    if (fd == -1)
    {
        printf("Could not open file");
        exit(1);
    }

    char c;
    while (((read(fd, &c, 1)) > 0))
    {

        write(1, &c, 1);

    }
    close(fd);
}

int main(int ac, char **av)
{

    int i;

    i = 1;
    if (ac < 2)
        return (0);
    while (i < ac)
    {
        read_file(av[i]);
        i++;
    }
    return 0;
}