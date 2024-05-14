/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:36:28 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/14 16:21:42 by lpaixao-         ###   ########.fr       */
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
	check_general_death(rules);
}

int	create_philo(t_rules *rules)
{
	static int	i = 0;
	int			verification;

	verification = 0;
	verification = pthread_create(&rules->arr_philos[i].ph, NULL, (void *)run_philo, &rules->arr_philos[i]);
	if (verification != 0)
		return (ERROR);
	rules->arr_philos[i].i = i + 1;
	i++;
	return (NO_ERROR);
}

void	*run_philo(void *philo)
{
	t_philo *ph;

	ph = (t_philo *)philo;
	while (ph->rules->dead_flag == ALIVE)
	{
		if (ph->i % 2 != 0)
			usleep(200);
		if (ph->rules->dead_flag == DEAD)
			return NULL;
		go_eat(philo);
		if (ph->rules->dead_flag == DEAD)
			return NULL;
		go_sleep(philo);
		if (ph->rules->dead_flag == DEAD)
			return NULL;
		go_think(philo);
		if (ph->rules->dead_flag == DEAD)
			return NULL;
	}
	return (NULL);
}

int	check_death(t_philo philo) // P mim tinha q receber o philo ponteiro aqui, por causa do muttex da print_msg, mas a função não está aceitando....
{
	struct timeval  current_time;

	gettimeofday(&current_time, NULL);
	if (current_time.tv_usec - philo.time_eaten < philo.rules->dying_time)
	{
		print_msg(current_time.tv_usec, philo.i, "died", &philo);
		return (DEAD);
	}
	return (ALIVE);
}

void	check_general_death(t_rules *rules)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < rules->philos)
		{
			if (check_death(rules->arr_philos[i]) == DEAD)
			{
				rules->dead_flag = DEAD;
				return ;
			}
			i++;
		}
		i = 0;
	}
}
