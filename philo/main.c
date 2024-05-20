/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:15:50 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/20 14:04:35 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	ac == 2 -> number of philosophers;
	ac == 3 -> time_to_die;
	ac == 4 -> time_to_eat;
	ac == 5 -> time_to_sleep;
	(OPTIONAL) ac == 6 -> number_of_times_each_philosopher_must_eat;
*/

int	main(int ac, char *av[])
{
	t_rules	rules;

	my_bzero(&rules, sizeof(t_rules));
	if (ac < 5 || ac > 6)
		return (ERROR);
	if (check_inputs(av) != NO_ERROR)
		return (ERROR);
	set_rules(ac, av, &rules);
	philos(&rules);
	clear_all(&rules);
}
