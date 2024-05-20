/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:36:28 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/20 16:57:10 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos(t_rules *rules)
{
	int	i;

	i = 1;
	while (i <= rules->philos)
	{
		if (create_philo(rules) == ERROR)
			break ;
		i++;
	}
	i = 0;
	while (i < rules->philos)
	{
		pthread_join(rules->arr_philos[i].ph, NULL);
		i++;
	}
	if (rules->philos == 1)
	{
		print_msg(get_time_now(), "died", &(rules->arr_philos[0]), DIED);
		return ;
	}
	check_general_death(rules);
}

int	create_philo(t_rules *rules)
{
	static int	i = 0;
	int			verification;

	verification = 0;
	verification = pthread_create(&rules->arr_philos[i].ph, NULL, \
			(void *)run_philo, &rules->arr_philos[i]);
	if (verification != 0)
		return (ERROR);
	rules->arr_philos[i].i = i + 1;
	i++;
	return (NO_ERROR);
}

void	*run_philo(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	if (ph->rules->philos == 1)
		return (NULL);
	while (ph->rules->dead_flag == ALIVE)
	{
		if (ph->i % 2 != 0)
			usleep(200);
		if (check_flag(ph->rules) != ALIVE)
			return (NULL);
		go_eat(philo);
		if (check_eaten_times(philo) == FULL)
			return (NULL);
		if (check_flag(ph->rules) != ALIVE)
			return (NULL);
		go_sleep(philo);
		if (check_flag(ph->rules) != ALIVE)
			return (NULL);
		go_think(philo);
		if (check_flag(ph->rules) != ALIVE)
			return (NULL);
	}
	return (NULL);
}

int	check_death(t_philo *philo)
{
	if ((get_time_now() - philo->time_eaten >= philo->rules->dying_time) \
			&& philo->finished != FULL)
	{
		print_msg(get_time_now(), "died", philo, DIED);
		return (DEAD);
	}
	return (ALIVE);
}

void	check_general_death(t_rules *rules)
{
	int	i;

	i = 0;
	while (rules->dead_flag != FULL)
	{
		while (i < rules->philos)
		{
			pthread_mutex_lock(&rules->died);
			if (check_death(&(rules->arr_philos[i])) == DEAD)
			{
				rules->dead_flag = DEAD;
				return ;
			}
			if (rules->dead_flag == FULL)
			{
				pthread_mutex_unlock(&rules->died);
				clear_all(rules);
				return ;
			}
			pthread_mutex_unlock(&rules->died);
			i++;
		}
		i = 0;
	}
}
