/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:26:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/14 16:17:59 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_eat(t_philo *philo)
{
	t_philo			*next;
	int				i_next;
	struct timeval	current_time;

	next = NULL;
	i_next = 1;
	if (philo->i != philo->rules->philos)
		i_next = philo->i + 1;
	next = &philo->rules->arr_philos[i_next - 1];
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&next->fork);
	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec - philo->time_eaten < philo->rules->dying_time)
	{
		philo->rules->dead_flag = DEAD;
		return ;
	}
	philo->time_eaten = current_time.tv_usec;
	print_msg(philo->time_eaten, philo->i, "is eating", philo);
	usleep(philo->rules->eating_time * 1000);// usleep is in microseconds, input is in miliseconds
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&next->fork);
}

void	go_sleep(t_philo *philo)
{
	struct timeval  current_time;

	gettimeofday(&current_time, NULL);
	print_msg(current_time.tv_usec, philo->i, "is sleeping", philo);
//	printf("%ld %i is eating\n", philo->time_eaten, philo->i);	
	usleep(philo->rules->sleeping_time * 1000);
}

void	go_think(t_philo *philo)
{
	struct timeval  current_time;

	gettimeofday(&current_time, NULL);
	print_msg(current_time.tv_usec, philo->i, "is thinking", philo);
	//Setar um tempo de usleep
}
