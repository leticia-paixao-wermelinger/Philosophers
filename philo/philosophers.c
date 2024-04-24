/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:36:28 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/04/24 16:50:49 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philos(t_rules *rules)
{
	int	i;

	i = 1;
	while (i <= rules->philos)
	{
		create_philo(rules);
		i++;
	}
	i = 1;
	printf("Apos todas as threads, arr de philos:\n");
	while (i <= rules->philos)
	{
		printf("Thread %i tem valor %i\n", i, rules->arr_philos[i - 1]);
		i++;
	}
}

void	create_philo(t_rules *rules)
{
	pthread_t	philosopher;
	static int	i = 0;

	printf("Vai criar thread %d\n", (i + 1));
	rules->arr_philos[i] = pthread_create(&philosopher, NULL, (void *)run_philo, rules);
	i++;
	pthread_join(philosopher, NULL);
}

void	*run_philo(t_rules *rules)
{
	printf("Rodando thread\n");
	(void)rules;
	return (NULL);
}
