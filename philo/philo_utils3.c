/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:11:44 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/28 19:16:27 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_threads(t_philo *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_join(arr[i].ph, NULL) != 0)
			return ;
		i++;
	}
}

void	improved_usleep(long int wait_time)
{
	long int	time;

	time = get_time_now();
	while (get_time_now() - time < wait_time)
		usleep(100);
}

void	print_death(long int current_time, char *str, \
			t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->rules->go_print);
	print_color(status);
	printf("%ld %i %s\n", current_time, philo->i, str);
	printf("\033[0m");
	pthread_mutex_unlock(&philo->rules->go_print);
}
