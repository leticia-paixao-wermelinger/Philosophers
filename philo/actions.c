
#include "philo.h"

/*
 * usleep is in microseconds, input is in miliseconds
*/

int	go_eat(t_philo *philo)
{
	if (philo->i % 2 == 0)
		return (try_eat(philo, philo->next, philo));
	else
		return (try_eat(philo->next, philo, philo));
}

int	try_eat(t_philo *first, t_philo *seccond, t_philo *philo)
{
	while (check_flag(philo->rules) == ALIVE)
	{
		if (lock_fork(first, philo) == NO_ERROR)
		{
			while (check_flag(philo->rules) == ALIVE)
			{
				if (lock_fork(seccond, philo) == NO_ERROR)
				{
					eating(philo);
					unlock_fork(seccond);
					unlock_fork(first);
					return (NO_ERROR);
				}
				else if (check_flag(philo->rules) != ALIVE)
				{
					unlock_fork(first);
					return (ERROR);
				}
			}
			unlock_fork(first);
		}
	}
	return (ERROR);
}

void	eating(t_philo *philo)
{
	philo->time_eaten = get_time_now();
	print_msg(philo->time_eaten, "is eating", philo, EATING);
	philo->ate_n_times++;
	improved_usleep(philo->rules->eating_time);
}

void	go_sleep(t_philo *philo)
{
	print_msg(get_time_now(), "is sleeping", philo, SLEEPING);
	improved_usleep(philo->rules->sleeping_time);
}

void	go_think(t_philo *philo)
{
	long int	time_to_think;

	print_msg(get_time_now(), "is thinking", philo, THINKING);
	if (philo->rules->philos % 2 == 0)
		return ;
	time_to_think = (philo->rules->eating_time * 2) \
			- philo->rules->sleeping_time;
	if (time_to_think < 0)
		time_to_think = 0;
	improved_usleep(time_to_think);
}
