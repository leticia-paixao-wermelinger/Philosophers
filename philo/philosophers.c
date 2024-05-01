/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:36:28 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/01 20:49:41 by lpaixao-         ###   ########.fr       */
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
	check_death(rules);
}

int	create_philo(t_rules *rules)
{
	static int	i = 0;
	int			verification;

	verification = 0;
	printf("Vai criar thread %d\n", (i + 1));
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
		printf("Rodando thread de philosopher %d\n", ph->i);
		go_eat(philo);
		go_sleep(philo);
		go_think(philo);
	}
	return (NULL);
}

void	check_death(t_rules *rules)
{
	int	i;

	i = 0;
	while (1)
	{
		while (i < rules->philos)
		{
			if (rules->arr_philos[i].dead == DEAD)
				rules->dead_flag = DEAD;
			i++;
		}
		i = 0;
	}
}
