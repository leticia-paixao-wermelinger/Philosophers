/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:15:50 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/04/21 12:57:59 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	ac == 2 -> number of philosophers;
	ac == 3 -> time_to_die;
	ac == 4 -> time_to_eat;
	ac == 5 -> tipe_to_sleep;
	(OPTIONAL) ac == 6 -> number_of_times_each_philosopher_must_eat;
*/

int	main(int ac, char *av[])
{
	t_inputs	*inputs;

	my_bzero(&inputs, sizeof(t_inputs));
	if (ac < 5 || ac > 6)
		return (ERROR);
	if (check_inputs(av) != NO_ERROR)
		return (ERROR);
	printf("Passou pelas validações de erro\n");
	inputs = set_inputs(ac, av);
	printf("Número de filósofos: %i\n", inputs->philos);
	printf("Tempo para morrer: %i\n", inputs->dying_time);
	printf("Tempo para comer: %i\n", inputs->eating_time);
	printf("Tempo para dormir: %i\n", inputs->sleeping_time);
	if (ac == 6)
		printf("Quantidade de vezes que ira comer: %i\n", inputs->n_times_to_eat);
}
