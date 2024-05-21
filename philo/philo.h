/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:15:44 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/05/21 14:39:39 by lpaixao-         ###   ########.fr       */
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

enum e_status {
	EATING = 3,
	SLEEPING = 4,
	THINKING = 5,
	DIED = 6,
	FULL = 7,
	EMPTY = 8,
	FORK = 9
};

typedef pthread_mutex_t	t_mutex;
typedef struct s_rules	t_rules;

typedef struct s_philo
{
	pthread_t		ph;
	t_mutex			fork;
	int				i;
	struct s_philo	*next;
	t_rules			*rules;
	long int		time_eaten;
	int				ate_n_times;
	int				finished;
	t_mutex			mutex_eaten_times;
}	t_philo;

typedef struct s_rules
{
	int			philos;
	t_philo		*arr_philos;
	long int	dying_time;
	long int	eating_time;
	long int	sleeping_time;
	int			n_times_to_eat;
	int			dead_flag;
	int			nbr_ph_full;
	t_mutex		go_print;
	t_mutex		died;
	t_mutex		count_philos;
}	t_rules;

int				check_inputs(char *av[]);
long long int	my_atoll(const char *nptr);
int				my_atoi(const char *nptr);
size_t			my_strlen(const char *s);
int				is_num(char *str);
int				is_pos(char *str);
int				is_long_int(char *str);
void			set_rules(int ac, char *av[], t_rules *rules);
void			set_philo_prop(t_rules *rules);
void			my_bzero(void *s, size_t n);
void			philos(t_rules *rules);
int				create_philo(t_rules *rules);
void			set_next(t_rules *rules, int i);
void			*run_philo(void *philo);
void			declare_philo(t_philo *philo);
void			eat(t_philo *philo);
void			clear_all(t_rules *rules);
void			go_eat(t_philo *philo);
void			eating(t_philo *philo);
void			*one_philo(t_philo *philo);
void			go_sleep(t_philo *philo);
void			go_think(t_philo *philo);
void			check_general_death(t_rules *rules);
int				check_death(t_philo *philo);
int				check_flag(t_rules *rules);
long int		get_time_now(void);
int				check_eaten_times(t_philo *philo);
void			print_msg(long int current_time, char *str, \
			t_philo *philo, int status);
void			print_philos(t_rules *rules);
void			print_test(long int current_time, char *str, t_philo *philo, int extra);
#endif
