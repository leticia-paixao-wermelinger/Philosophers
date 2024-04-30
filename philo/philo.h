/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:15:44 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/04/30 18:05:04 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

enum e_error {
	NO_ERROR = 1,
	ERROR = -1
};

typedef struct  s_rules t_rules;

typedef struct	s_philo
{
	pthread_t		ph;
	pthread_mutex_t	fork;
//	int				check_lock;
	int				i;
	t_rules			*rules;
}	t_philo;

typedef struct	s_rules
{
	int			philos;
	t_philo		*arr_philos;
	int			dying_time;
	int			eating_time;
	int			sleeping_time;
	int			n_times_to_eat;
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
#endif
