/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:25:43 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/14 15:38:22 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_rules(int ac, char *av[], t_rules *rules)
{
	rules->philos = my_atoi(av[1]);
	rules->arr_philos = malloc(rules->philos * sizeof(t_philo));
	set_philo_prop(rules);
	rules->dying_time = my_atoi(av[2]);
	rules->eating_time = my_atoi(av[3]);
	rules->sleeping_time = my_atoi(av[4]);
	if (ac == 6)
		rules->n_times_to_eat = my_atoi(av[5]);
	rules->dead_flag = ALIVE;
//	gettimeofday(&rules->current_time, NULL);
}

void	set_philo_prop(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philos)
	{
		rules->arr_philos[i].i = 0;
//		rules->arr_philos[i].check_lock = 0;
		rules->arr_philos[i].time_eaten = 0;
//		rules->arr_philos[i].dead = 0;
		rules->arr_philos[i].rules = rules;
		pthread_mutex_init(&rules->arr_philos[i].fork, NULL);
		pthread_mutex_init(&rules->arr_philos[i].go_print, NULL);
		i++;
	}
}

void	print_philos(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philos)
	{
		printf("Filófoso %d:\n", rules->arr_philos[i].i);
		printf("Identificador da thread: %ld\n", (long)rules->arr_philos[i].ph);
		printf("Identificador do mutex: %p\n", (void*)&rules->arr_philos[i].fork);
		i++;
	}
}

void	clear_all(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philos)
	{
		pthread_mutex_destroy(&rules->arr_philos[i].fork);
		i++;
	}
	free(rules->arr_philos);
	rules->arr_philos = NULL;
}
