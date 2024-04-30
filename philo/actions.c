/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 14:26:35 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/04/30 19:04:46 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo)
{
	t_philo	*next;
	int		i_next;

	next = NULL;
	i_next = 0;
	if (philo->i != (philo->rules->philos - 1))
		i_next = philo->i + 1;
	next = philo->rules->arr_philos[i_next];
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(&next->fork);
	printf("Philosopher %i está comendo.\n", philo->i);	
//	usleep(); usleep is in microseconds, input is in miliseconds
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&next->fork);
}
