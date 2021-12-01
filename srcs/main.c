/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:36:43 by juan              #+#    #+#             */
/*   Updated: 2021/12/01 18:21:07 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/struct.h"
#include "../inc/macro.h"
#include "../lib/GNL/get_next_line.h"
#include "../lib/libft/libft.h"
#include <stdio.h>

void	init_struct(t_philo *philo)
{
	philo->number_of_philosophers = 0;
	philo->time_to_eat = 0;
	philo->time_to_sleep = 0;
	philo->time_to_think = 0;
	philo->time_to_die = 0;
	philo->number_of_times_each_philosopher_must_eat = 0;
	return ;
}

int	main(int ac, char *av[])
{
	t_philo	philo;
	int		i;

	i = 0;
	if (ac == 5 || ac == 6)
		catch_int(av, &philo);
	else 
		error_san(ERRNO0, ERRMSG0);

	return (0);
}
