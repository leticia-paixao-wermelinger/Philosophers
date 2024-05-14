/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:15:44 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/14 16:18:18 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

enum e_error {
	NO_ERROR = 1,
	ERROR = -1,
	ALIVE = 1,
	DEAD = 2
};

typedef struct  s_rules t_rules;

typedef struct	s_philo
{
	pthread_t		ph;
	pthread_mutex_t	fork;
	int				i;
	t_rules			*rules;
	long int		time_eaten;
	pthread_mutex_t	go_print;
//	int				dead;
}	t_philo;

typedef struct	s_rules
{
	int				philos;
	t_philo			*arr_philos;
	long int		dying_time;
	long int		eating_time;
	long int		sleeping_time;
	int				n_times_to_eat;
	int				dead_flag;
//	struct timeval	current_time;
}	t_rules;

int			check_inputs(char *av[]);
long int	my_atol(const char *nptr);
int			my_atoi(const char *nptr);
size_t		my_strlen(const char *s);
int			is_num(char *str);
int			is_pos(char *str);
int			is_int(char *str);
void		set_rules(int ac, char *av[], t_rules *rules);
void		set_philo_prop(t_rules *rules);
void		my_bzero(void *s, size_t n);
void		philos(t_rules *rules);
int			create_philo(t_rules *rules);
void		*run_philo(void *philo);
void		declare_philo(t_philo *philo);
void		print_philos(t_rules *rules);
void		eat(t_philo *philo);
void		clear_all(t_rules *rules);
void		go_eat(t_philo *philo);
void		go_sleep(t_philo *philo);
void		go_think(t_philo *philo);
void		check_general_death(t_rules *rules);
int			check_death(t_philo philo);
void		print_msg(long int current_time, int i, char *str, t_philo *philo);
#endif
