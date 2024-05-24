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

int	go_eat(t_philo *philo)
{
	if (philo->i != philo->rules->philos)
		return (try_eat(philo, philo->next, philo));
	else
		return (try_eat(philo->next, philo, philo));
}

int	try_eat(t_philo *first, t_philo *seccond, t_philo *philo)
{
	if (lock_fork(first) == NO_ERROR)
	{
		while (check_flag(philo->rules) == ALIVE)
		{
			if (lock_fork(seccond) == NO_ERROR)
			{
				eating(philo);
				unlock_fork(first);
				unlock_fork(seccond);
				return (NO_ERROR);
			}
			else if (check_flag(philo->rules) != ALIVE)
			{
				unlock_fork(first);
				return (ERROR);
			}
		}
		unlock_fork(first);
	}
	return (ERROR);
}

void	eating(t_philo *philo)
{
	philo->time_eaten = get_time_now();
	print_msg(philo->time_eaten, "is eating", philo, EATING);
	philo->ate_n_times++;
	usleep(philo->rules->eating_time * 1000);
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
