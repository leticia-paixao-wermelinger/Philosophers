/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:26:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/19 20:22:15 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	go_eat(t_philo *philo)
{
	t_philo			*next;
	int				i_next;

	next = NULL;
	i_next = 1;
	if (philo->i != philo->rules->philos)
		i_next = philo->i + 1;
	next = &philo->rules->arr_philos[i_next - 1];
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&next->fork);
	if (get_time_now() - philo->time_eaten >= philo->rules->dying_time)
	{
		philo->rules->dead_flag = DEAD;
		return ;
	}
	philo->time_eaten = get_time_now();
	print_msg(philo->time_eaten, "is eating", philo, EATING);
	philo->ate_n_times++;
	usleep(philo->rules->eating_time * 1000);// usleep is in microseconds, input is in miliseconds
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&next->fork);
}

void	go_sleep(t_philo *philo)
{
	print_msg(get_time_now(), "is sleeping", philo, SLEEPING);
	usleep(philo->rules->sleeping_time * 1000);
}

void	go_think(t_philo *philo)
{
	print_msg(get_time_now(), "is thinking", philo, THINKING);
	//Setar um tempo de usleep
}
