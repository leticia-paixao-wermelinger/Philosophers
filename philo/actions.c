/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:26:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/21 14:26:35 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
 * usleep is in microseconds, input is in miliseconds
*/

void	go_eat(t_philo *philo)
{
	if (philo->i != philo->rules->philos)
	{
		pthread_mutex_lock(&philo->mutex_fork);
		print_msg(philo->time_eaten, "has taken a fork", philo, FORK);
		pthread_mutex_lock(&philo->next->mutex_fork);
		print_msg(philo->time_eaten, "has taken a fork", philo, FORK);
		eating(philo);
		pthread_mutex_unlock(&philo->mutex_fork);
		pthread_mutex_unlock(&philo->next->mutex_fork);
	}
	else
	{
		pthread_mutex_lock(&philo->next->mutex_fork);
		print_msg(philo->time_eaten, "has taken a fork", philo, FORK);
		pthread_mutex_lock(&philo->mutex_fork);
		print_msg(philo->time_eaten, "has taken a fork", philo, FORK);
		eating(philo);
		pthread_mutex_unlock(&philo->next->mutex_fork);
		pthread_mutex_unlock(&philo->mutex_fork);
	}
}

void	eating(t_philo *philo)
{
	philo->time_eaten = get_time_now();
	print_msg(philo->time_eaten, "is eating", philo, EATING);
	philo->ate_n_times++;
	usleep(philo->rules->eating_time * 1000);
}

void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_fork);
	print_msg(philo->time_eaten, "has taken a fork", philo, FORK);
	pthread_mutex_unlock(&philo->mutex_fork);
	return (NULL);
}

void	go_sleep(t_philo *philo)
{
	print_msg(get_time_now(), "is sleeping", philo, SLEEPING);
	usleep(philo->rules->sleeping_time * 1000);
}

void	go_think(t_philo *philo)
{
	print_msg(get_time_now(), "is thinking", philo, THINKING);
}
