/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 16:25:43 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/04/21 12:54:37 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_inputs	*set_inputs(int ac, char *av[])
{
	t_inputs	*inputs;

	inputs = malloc(sizeof(t_inputs));
	inputs->philos = my_atoi(av[1]);
	inputs->dying_time = my_atoi(av[2]);
	inputs->eating_time = my_atoi(av[3]);
	inputs->sleeping_time = my_atoi(av[4]);
	if (ac == 6)
		inputs->n_times_to_eat = my_atoi(av[5]);
	return (inputs);
}
