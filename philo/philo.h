/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 11:15:44 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/04/21 12:51:49 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>

enum e_error {
	NO_ERROR = 1,
	ERROR = -1
};

typedef struct	s_inputs
{
	int	philos;
	int	dying_time;
	int	eating_time;
	int	sleeping_time;
	int	n_times_to_eat;
}	t_inputs;

int			check_inputs(char *av[]);
long int	my_atol(const char *nptr);
int			my_atoi(const char *nptr);
size_t		my_strlen(const char *s);
int			is_num(char *str);
int			is_pos(char *str);
int			is_int(char *str);
t_inputs	*set_inputs(int ac, char *av[]);
void		my_bzero(void *s, size_t n);
#endif
