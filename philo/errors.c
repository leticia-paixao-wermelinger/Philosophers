
#include "philo.h"

int	check_inputs(char *av[])
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_num(av[i]) == ERROR)
			return (ERROR);
		if (is_pos(av[i]) == ERROR)
			return (ERROR);
		if (is_long_int(av[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[0] != '-' && str[0] != '+')
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

int	is_pos(char *str)
{
	if (str[0] == '-')
		return (ERROR);
	return (NO_ERROR);
}

int	is_long_int(char *str)
{
	long long int	n;

	if (my_strlen(str) > 11)
		return (ERROR);
	n = my_atoll(str);
	if (n > LONG_MAX || n < LONG_MIN)
		return (ERROR);
	return (NO_ERROR);
}
