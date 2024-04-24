/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:25:43 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/04/23 18:07:22 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_rules(int ac, char *av[], t_rules *rules)
{
	rules->philos = my_atoi(av[1]);
	rules->arr_philos = malloc(rules->philos * sizeof(int));
	rules->dying_time = my_atoi(av[2]);
	rules->eating_time = my_atoi(av[3]);
	rules->sleeping_time = my_atoi(av[4]);
	if (ac == 6)
		rules->n_times_to_eat = my_atoi(av[5]);
}
