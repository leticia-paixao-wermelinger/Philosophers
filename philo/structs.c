
#include "philo.h"

void	set_rules(int ac, char *av[], t_rules *rules)
{
	rules->philos = my_atol(av[1]);
	rules->arr_philos = malloc(rules->philos * sizeof(t_philo));
	set_philo_prop(rules);
	rules->dying_time = my_atol(av[2]);
	rules->eating_time = my_atol(av[3]);
	rules->sleeping_time = my_atol(av[4]);
	if (ac == 6)
		rules->n_times_to_eat = my_atol(av[5]);
	else
		rules->n_times_to_eat = ERROR;
	pthread_mutex_init(&rules->go_print, NULL);
	rules->end_flag = ALIVE;
	rules->nbr_ph_full = rules->philos;
	pthread_mutex_init(&rules->died, NULL);
	pthread_mutex_init(&rules->count_philos, NULL);
}

void	set_philo_prop(t_rules *rules)
{
	int				i;

	i = 0;
	while (i < rules->philos)
	{
		rules->arr_philos[i].i = 0;
		rules->arr_philos[i].next = NULL;
		rules->arr_philos[i].time_eaten = get_time_now();
		rules->arr_philos[i].rules = rules;
		rules->arr_philos[i].fork_status = UNLOCKED;
		pthread_mutex_init(&(rules->arr_philos[i].mutex_fork_status), NULL);
		pthread_mutex_init(&(rules->arr_philos[i].mutex_fork), NULL);
		rules->arr_philos[i].ate_n_times = 0;
		rules->arr_philos[i].finished = ALIVE;
		pthread_mutex_init(&(rules->arr_philos[i].mutex_eaten_times), NULL);
		i++;
	}
}

void	set_next(t_rules *rules, int i)
{
	if (i != rules->philos)
		rules->arr_philos[i - 1].next = &(rules->arr_philos[i]);
	else
		rules->arr_philos[i - 1].next = &(rules->arr_philos[0]);
}

void	print_philos(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philos)
	{
		printf("Filófoso %d:\n", rules->arr_philos[i].i);
		printf("Identificador da thread: %ld\n", (long)rules->arr_philos[i].ph);
		printf("Identificador do mutex: %p\n", \
			(void *)&rules->arr_philos[i].mutex_fork);
		i++;
	}
}

void	clear_all(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philos)
	{
		pthread_mutex_destroy(&rules->arr_philos[i].mutex_fork);
		pthread_mutex_destroy(&rules->arr_philos[i].mutex_eaten_times);
		i++;
	}
	pthread_mutex_destroy(&rules->go_print);
	pthread_mutex_destroy(&rules->died);
	pthread_mutex_destroy(&rules->count_philos);
	free(rules->arr_philos);
	rules->arr_philos = NULL;
}
