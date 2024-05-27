/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:40:00 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/21 21:20:03 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_flag(t_rules *rules)
{
	pthread_mutex_lock(&rules->died);
	if (rules->end_flag != ALIVE)
	{
		pthread_mutex_unlock(&rules->died);
		return (DEAD);
	}
	pthread_mutex_unlock(&rules->died);
	return (ALIVE);
}

long int	get_time_now(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1e3 + current_time.tv_usec / 1e3);
}

void	count_eaten_times(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_eaten_times);
	philo->ate_n_times++;
	pthread_mutex_unlock(&philo->mutex_eaten_times);
}

int	check_eaten_times(t_philo *philo)
{
	pthread_mutex_lock(&philo->rules->died);
	pthread_mutex_lock(&philo->mutex_eaten_times);
	if ((philo->ate_n_times >= philo->rules->n_times_to_eat) \
			&& (philo->rules->n_times_to_eat >= 0))
	{
		pthread_mutex_lock(&philo->rules->count_philos);
		philo->rules->nbr_ph_full--;
		philo->finished = FULL;
		if (philo->rules->nbr_ph_full == 0)
			philo->rules->end_flag = FULL;
		pthread_mutex_unlock(&philo->rules->count_philos);
		pthread_mutex_unlock(&philo->rules->died);
		pthread_mutex_unlock(&philo->mutex_eaten_times);
		return (FULL);
	}
	pthread_mutex_unlock(&philo->mutex_eaten_times);
	pthread_mutex_unlock(&philo->rules->died);
	return (EMPTY);
}

void	print_color(int status)
{
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
}