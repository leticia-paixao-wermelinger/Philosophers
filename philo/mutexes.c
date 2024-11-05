
#include "philo.h"

int	lock_fork(t_philo *ph_fork, t_philo *ph_acting)
{
	pthread_mutex_lock(&(ph_fork->mutex_fork_status));
	if (ph_fork->fork_status == UNLOCKED)
	{
		pthread_mutex_lock(&ph_fork->mutex_fork);
		print_msg(ph_acting->time_eaten, "has taken a fork", ph_acting, FORK);
		ph_fork->fork_status = LOCKED;
		pthread_mutex_unlock(&(ph_fork->mutex_fork_status));
		return (NO_ERROR);
	}
	else if (ph_fork->fork_status == LOCKED)
	{
		pthread_mutex_unlock(&(ph_fork->mutex_fork_status));
		return (ERROR);
	}
	pthread_mutex_unlock(&(ph_fork->mutex_fork_status));
	return (ERROR);
}

void	unlock_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mutex_fork);
	pthread_mutex_lock(&(philo->mutex_fork_status));
	philo->fork_status = UNLOCKED;
	pthread_mutex_unlock(&(philo->mutex_fork_status));
}
/*
void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex_fork);
	print_msg(philo->time_eaten, "has taken a fork", philo, FORK);
	pthread_mutex_unlock(&philo->mutex_fork);
	return (NULL);
}*/
