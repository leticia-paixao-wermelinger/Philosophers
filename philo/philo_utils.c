/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:14:59 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/21 14:35:02 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	my_atoll(const char *nptr)
{
	int				sign;
	long long int	n;
	int				i;

	sign = 1;
	n = 0;
	i = 0;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return (n * sign);
}

int	my_atoi(const char *nptr)
{
	int	sign;
	int	n;
	int	i;

	sign = 1;
	n = 0;
	i = 0;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && nptr[i] >= 48 && nptr[i] <= 57)
	{
		n = n * 10 + nptr[i] - '0';
		i++;
	}
	return (n * sign);
}

size_t	my_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	my_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}

void	print_msg(long int current_time, char *str, t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->rules->go_print);
	if (status == EATING)
		printf("\033[0;32m");
	else if (status == SLEEPING)
		printf("\033[0;34m");
	else if (status == THINKING)
		printf("\033[0;33m");
	else if (status == DIED)
		printf("\033[0;31m");
	else if (status == FORK)
		printf("\033[0;90m");
	printf("%ld %i %s\n", current_time, philo->i, str);
	printf("\033[0m");
	pthread_mutex_unlock(&philo->rules->go_print);
}

void	print_test(long int current_time, char *str, t_philo *philo, int extra)
{
	pthread_mutex_lock(&philo->rules->go_print);
	printf("%ld %i %s %i\n", current_time, philo->i, str, extra);
	pthread_mutex_unlock(&philo->rules->go_print);
}
