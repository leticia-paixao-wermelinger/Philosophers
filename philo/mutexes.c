/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:17:16 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/22 14:30:43 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	lock_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex_fork_status));
	if (philo->fork_status == UNLOCKED)
	{
		pthread_mutex_lock(&philo->mutex_fork);
		print_msg(philo->time_eaten, "has taken a fork", philo, FORK);
		philo->fork_status = LOCKED;
		pthread_mutex_unlock(&(philo->mutex_fork_status));
		return (NO_ERROR);
	}
	else if (philo->fork_status == LOCKED)
	{
		pthread_mutex_unlock(&(philo->mutex_fork_status));
		return (ERROR);
	}
	pthread_mutex_unlock(&(philo->mutex_fork_status));
	return (ERROR);
}

void	unlock_fork(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex_fork_status));
	pthread_mutex_unlock(&philo->mutex_fork);
	philo->fork_status = UNLOCKED;
	pthread_mutex_unlock(&(philo->mutex_fork_status));
}
/*
void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_fork);
	print_msg(philo->time_eaten, "has taken a fork", philo, FORK);
	pthread_mutex_unlock(&philo->mutex_fork);
	return (NULL);
}*/
