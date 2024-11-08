
#include "philo.h"
/*
	ac == 2 -> number of philosophers;
	ac == 3 -> time_to_die (milliseconds);
	ac == 4 -> time_to_eat (milliseconds);
	ac == 5 -> time_to_sleep (milliseconds);
	(OPTIONAL) ac == 6 -> number_of_times_each_philosopher_must_eat;
*/
//static void	print_philos(t_rules *rules);

int	main(int ac, char *av[])
{
	t_rules	rules;

	my_bzero(&rules, sizeof(t_rules));
	if (ac < 5 || ac > 6)
	{
		printf("\033[0;31m Please, insert a valid input. \033[0m \n");
		return (ERROR);
	}
	if (check_inputs(av) != NO_ERROR)
	{
		printf("\033[0;31mPlease, insert only numeric positive arguments:\n");
		printf("number_of_philosophers time_to_die time_to_eat time_to_sleep");
		printf("[number_of_times_each_philosopher_must_eat]\033[0m \n");
		return (ERROR);
	}
	set_rules(ac, av, &rules);
	philos(&rules);
	join_threads(rules.arr_philos, rules.philos);
	clear_all(&rules);
}

/*
static void	print_philos(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philos)
	{
		printf("Filófoso %d:\n", rules->arr_philos[i].i);
		printf("Identificador da thread: %ld\n", (long)rules->arr_philos[i].ph);
		printf("Identificador do mutex principal: %p\n", \ 
				&(rules->arr_philos[i].mutex_fork));
		printf("Identificador do mutex do status: %p\n", \
				&(rules->arr_philos[i].mutex_fork_status));
		i++;
	}
}
*/