/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaixao- <lpaixao-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 13:45:34 by lpaixao-          #+#    #+#             */
/*   Updated: 2024/04/20 15:05:03 by lpaixao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_inputs(char *av[])
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_num(av[i]) == ERROR)
			return (ERROR);
		if (is_pos(av[i]) == ERROR)
			return (ERROR);
		if (is_int(av[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[0] != '-' && str[0] != '+')
			return (ERROR);
		i++;
	}
	return (NO_ERROR);
}

int	is_pos(char *str)
{
	if (str[0] == '-')
		return (ERROR);
	return (NO_ERROR);
}

int	is_int(char *str)
{
	long int	n;

	if (my_strlen(str) > 11)
		return (ERROR);
	n = my_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (ERROR);
	return (NO_ERROR);
}
