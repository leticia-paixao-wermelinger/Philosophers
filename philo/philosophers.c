/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:36:28 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/21 21:25:22 by lpaixao-         ###   ########.fr       */
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
	check_general_death(rules);
/*	i = 0;
	printf("vai dar join nas threads c size valendo %i\n", rules->philos);
	while (i < rules->philos)
	{
		printf("i vale %i\n", i);
		if (pthread_join(rules->arr_philos[i].ph, NULL) != 0)
			break ;
		printf("Passou pela join\n");
		i++;
	}
	printf("Saiu no while da join\n");*/
}

int	create_philo(t_rules *rules)
{
	static int	i = 0;
	int			verification;

	verification = 0;
	rules->arr_philos[i].i = i + 1;
	set_next(rules, (i + 1));
	verification = pthread_create(&rules->arr_philos[i].ph, NULL, \
			(void *)run_philo, &rules->arr_philos[i]);
	if (verification != 0)
		return (ERROR);
	i++;
	return (NO_ERROR);
}

void	*run_philo(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	//ph->time_eaten = get_time_now();
	if (ph->i % 2 != 0)
		usleep(100);
	while (check_flag(ph->rules) == ALIVE)
	{
		//printf("Está no loop do filo %i\n", ph->i);
		if (go_eat(philo) == ERROR)
			return (NULL);
		//printf("%i terminou de comer\n", ph->i);
		if (check_eaten_times(philo) == FULL)
			return (NULL);
		if (check_flag(ph->rules) != ALIVE)
			return (NULL);
		go_sleep(philo);
		if (check_flag(ph->rules) != ALIVE)
			return (NULL);
		go_think(philo);
	}
	return (NULL);
}

int	check_death(t_philo *philo)
{
	if (((get_time_now() - philo->time_eaten) >= philo->rules->dying_time)
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

	while (rules->end_flag != FULL)
	{
		i = 0;
		while ((i < rules->philos) && (rules->end_flag != FULL))
		{
			pthread_mutex_lock(&rules->died);
			if ((check_death(&(rules->arr_philos[i])) == DEAD) && rules->end_flag != FULL)
			{
				rules->end_flag = DEAD;
				pthread_mutex_unlock(&rules->died);
				return ;
			}
			if (rules->end_flag == FULL)
			{
				pthread_mutex_unlock(&rules->died);
				return ;
			}
			pthread_mutex_unlock(&rules->died);
			i++;
		}
	}
}