/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <jbuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:43:00 by juan              #+#    #+#             */
/*   Updated: 2022/01/18 17:51:51 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"	
#include "../inc/struct.h"	
#include "../inc/macro.h"	
#include "../lib/GNL/get_next_line.h"
#include "../lib/libft/libft.h"
#include <stdio.h>

int	catch_int(char **av, t_philo *philo)
{
	int	i;
	int	j;
	int	errorp;

	i = 1;
	j = 0;
	errorp = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				error_san(ERRNO1, ERRMSG1, errorp);
				return (errorp);
			}
			j++;
		}
		i++;
		j = 0;
	}
	if (errorp == 0)
		return (dispatch(av, philo, errorp));
	return (errorp);
}

int	dispatch(char **av, t_philo *philo, int errorp)
{
	philo->number_of_philosophers = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	if (philo->time_to_die >= 1000 || philo->time_to_eat >= 1000
		|| philo->time_to_sleep >= 1000)
	{
		error_san(ERRNO3, ERRMSG3, errorp);
		return (1);
	}
	return (errorp);
}
